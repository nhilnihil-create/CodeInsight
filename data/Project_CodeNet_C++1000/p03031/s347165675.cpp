#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1);

int main(void)
{
    ll n, m, ans=0;
    cin >> n >> m;
    vector<vector<ll>> s(m);
    rep(i,m){
        ll k;
        cin >> k;
        rep(j,k){
            ll a;
            cin >> a;
            a--;
            s[i].push_back(a);
        }
    }
    vector<ll> p(m);
    rep(i,m) cin >> p[i];
    rep(bit,(1<<n)){
        bool ok = true;
        rep(i,m){
            ll cnt = 0;
            for(auto on:s[i]){
                if(bit & (1<<on)) cnt++;
            }
            if(cnt%2 != p[i]) ok = false;
        }
        if(ok) ans++;
    }
    cout << ans << endl;
    return 0;
}