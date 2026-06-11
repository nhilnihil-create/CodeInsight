#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
int n, k, d[40];
vector<long long> s, v;
int main(void){

    cin >> n >> k;
    s.assign(n+1, 0);
    for(int i=1;i<=n;i++){
        cin >> s[i];
        s[i] += s[i-1];
    }

    fill(d, d+40, 0);
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            long long t = s[i] - s[j];
            for(int l=0;l<40;l++){
                d[l] += ((t>>l)&1);
            }
            v.push_back(t);
        }
    }
    long long ans = 0;
    for(int j=39;j>=0;j--){
        if(d[j] >= k){
            vector<long long> w;
            fill(d, d+40, 0);
            ans += (1LL<<j);
            for(int i=0;i<v.size();i++){
                if(((v[i]>>j)&1)==1){
                    for(int l=0;l<j;l++){
                        d[l] += ((v[i]>>l)&1);
                    }
                    w.push_back(v[i]);
                }
            }
            v.assign(w.begin(), w.end());
        }
    }
    cout << ans << endl;
}
