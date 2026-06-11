#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll n,m;
    cin >> n >> m;
    vector<ll> k(m);
    vector<vector<ll>> s(m);
    for(i = 0;i < m;++i){
        cin >> k.at(i);
        rep(j,k.at(i)){
            ll ss;
            cin >> ss;
            --ss;
            s.at(i).push_back(ss);
        }
    }
    vector<ll> p(m);
    for(i = 0;i < m;++i){
        cin >> p.at(i);
    }
    ll ans = 0;
    ll bit;
    for(bit = 0;bit < (1 << n);++bit){
        bool flag = true;
        for(i = 0;i < m;++i){
            ll tmp = 0;
            rep(j,k.at(i)){
                if(bit & (1 << s.at(i).at(j))){
                    ++tmp;
                }
            }
            if(tmp%2 != p.at(i)){
                flag = false;
                break;
            }
        }
        if(flag) ++ans;
    }
    cout << ans << endl;
    return 0;
}