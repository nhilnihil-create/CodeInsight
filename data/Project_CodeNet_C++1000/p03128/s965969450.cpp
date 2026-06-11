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
    ll match[10] = {0,2,5,5,4,5,6,3,7,6};
    vector<ll> a(m);
    for(i = 0;i < m;++i){
        cin >> a.at(i);
    }
    sort(all(a));
    vector<ll> dp(n+1,-1);
    dp.at(0) = 0;
    for(i = 0;i < n;++i){
        rep(j,m){
            if(i + match[a.at(j)] <= n){
                ll next = i + match[a.at(j)];
                dp.at(next) = max(dp.at(next), dp.at(i) + 1);
            }
        }
    }
    ll now = n;
    string ans;
    while(now){
        for(i = m-1;i >= 0;--i){
            if(now - match[a.at(i)] < 0) continue;
            if(dp.at(now - match[a.at(i)]) == dp.at(now) - 1){
                ans.push_back(a.at(i) + '0');
                now -= match[a.at(i)];
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}