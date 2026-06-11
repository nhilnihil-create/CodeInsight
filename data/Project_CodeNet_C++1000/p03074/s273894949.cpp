#include<bits/stdc++.h>
using namespace std;

#define Q int t; scanf("%d", &t); for(int q=1; q<=t; q++)
typedef long long int lli;
typedef pair<int, int> pi;
typedef pair<lli, int> pii;



int main()
{
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<int> v;
    v.push_back(0);
    for(int i=0; i<n; ){
        char c = s[i];
        int cnt = 0;
        while(i<n && s[i] == c){
            cnt++;
            i++;
        }
        v.push_back(cnt);
    }
    for(int i=1; i<v.size(); i++){
        v[i] += v[i-1];
    }
    int kk = k*2;
    int mod = 1;
    if(s[0] == '1') kk++, mod--;

    if(kk >= v.size()-1){
        cout << n << "\n";
        return 0;
    }
//    for(auto x: v){
//        cout << x << " ";
//    }
//    cout << endl;
    int ans = 0, i, j;
    int cnt=0;
    for(i=1, j=0; j<v.size(); ){
        if(cnt < k){
            j++;
            if(j%2 == mod) cnt++;
        }
        else if(cnt > k){
            if(i%2 == mod && i!=0) cnt--;
            i++;
        }
        else if(cnt == k){
            ans = max(ans, v[j]-v[i-1]);
            j++;
            if(j%2 == mod)cnt++;
        }
    }
    cout << ans << "\n";

    return 0;
}
