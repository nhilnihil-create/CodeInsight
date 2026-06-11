#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll n;
    cin >> n;
    vector<string> s(n);
    for(i = 0;i < n;++i){
        cin >> s.at(i);
    }
    ll k;
    ll ans = 0;
    rep(k, n){
        bool flag = true;
        for(i = 0;i < n;++i){
            rep(j,n){
                if(s.at((i+k)%n).at(j) != s.at((j+k)%n).at(i)){
                    flag = false;
                    break;
                }
                
            }
            if(!flag) break;
        }
        if(flag) ans += n;
    }
    cout << ans << endl;
    return 0;
}