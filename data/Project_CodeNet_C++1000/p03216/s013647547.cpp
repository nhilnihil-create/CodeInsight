#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll n;
    string s;
    cin >> n >> s;
    ll q;
    cin >> q;
    rep(i,q){
        ll k;
        cin >> k;
        ll now = 0;
        ll d = 0, m = 0, dm = 0;
        ll ans = 0;
        while(now < n){
            if(s[now] == 'D') ++d;
            else if(s[now] == 'M'){
                ++m;
                dm += d;
            }else if(s[now] == 'C'){
                ans += dm;
            }
            if(now - k + 1 >= 0){
                j = now - k + 1;
                if(s[j] == 'D'){
                    dm -= m;
                    --d;
                }
                else if(s[j] == 'M') --m;
            }
            ++now;
        }
        cout << ans << endl;
    }

    return 0;
}