#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

void chmin(ll &a, ll b) {if(a > b) a = b;}
const ll INF = 1LL<<59;

int main(){
    int a, b, q; cin >> a >> b >> q;
    vector<ll> s(a), t(b);
    rep(i,a) cin >> s[i];
    rep(i,b) cin >> t[i];
    s.push_back(-INF); s.push_back(INF); sort(ALL(s));
    t.push_back(-INF); t.push_back(INF); sort(ALL(t));
    rep(i,q){
        ll x; cin >> x;
        ll ans = INF;
        int si = lower_bound(ALL(s), x) - s.begin();
        int ti = lower_bound(ALL(t), x) - t.begin();
        for(int j = si-1; j <= si; ++j){//-INF,INFで配列外参照がない
            for(int k = ti-1; k<=ti; ++k){
                ll S = s[j];
                ll T = t[k];
                chmin(ans, abs(x - S) + abs(S - T));
                chmin(ans, abs(x - T) + abs(T - S));
            }
        }
        cout << ans << endl;
    }
}