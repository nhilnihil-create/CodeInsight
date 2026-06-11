#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
using namespace std;
typedef pair<ll,ll> pll;


ll n, d[55];
ll ans;
set<ll> S[2][25];
ll dp[110];
set<ll> s[2][25];
bool cando(ll star, ll t)
{
        ll pt = 0;
        ll cur = star;
        while(pt < n) {
                while(cur < 25 && s[0][cur].size() == 0 && s[1][cur].size() == 0) {
                        cur++;
                }
                if(cur == 25) return false;
                if(s[1][cur].size()) {
                        s[1][cur].erase(s[1][cur].begin());
                        cur += t;
                        pt++;
                        continue;
                }else {
                        ll mined = 25;
                        ll id = 0;
                        for(auto &i : s[0][cur]) {
                                if(24LL - d[i] < mined) {
                                        mined = 24 - d[i];
                                        id = i;
                                }
                        }
                        pt++;
                        s[1][mined].erase(id);
                        cur += t;
                        continue;

                }
        }
        return true;
}
bool ok(ll t)
{
        //set<pll> s[2][25];
        for(ll i=0;i<=1;i++) {
                for(ll j=0;j<=24;j++) s[i][j] = S[i][j];
        }
        for(ll i=0;i<=24;i++) {
                if(S[0][i].size() > 0) {
                        if(cando(i , t)) return true;
                }
        }
        return false;
}
int main()
{
        cin >> n;
        ans = 24;
        for(ll i=1;i<=n;i++) {
                cin >> d[i];
                ans = min(ans , d[i]);
                S[0][min(d[i], 24LL - d[i])].insert(i);
                S[1][max(d[i], 24LL - d[i])].insert(i);
        }
        ll ret = ans;
        for(ll i=ans;i>=0;i--){
                if(ok(i)) {
                        cout << i << endl; return 0;
                }
        }
        return 0;
}
