#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    vector<long long int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    vector<long long int> sa(n+1);
    for(int i=0; i<n; i++){
        sa[i+1] = sa[i] + a[i];
    }

    vector<long long int> b;
    for(int i=0; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            b.push_back(sa[j] - sa[i]);
        }
    }

    vector<long long int> c;
    bool flag = false;
    long long int ans = 0;
    for(int i=40; i>=0; i--){// 10^12 < 2^40
        vector<long long int> d;
        if(flag == false){
            for(long long int bb : b){
                if(bb >> i & 1) d.push_back(bb);
            }
            if((int)d.size() >= k){
                ans += (1LL << i);
                c = d;
                flag = true;
            }
        }
        else{
            for(long long int cc : c){
                if(cc >> i & 1) d.push_back(cc);
            }
            if((int)d.size() >= k){
                ans += (1LL << i);
                c = d;
            }
        }
        //cout << i << " : ";
        //for(long long int cc : c) cout << cc << " ";
        //cout << endl;
    }
    cout << ans << endl;
    return 0;
}