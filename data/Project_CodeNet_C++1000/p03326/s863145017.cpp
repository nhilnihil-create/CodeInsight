#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(ll i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<int, int>;
#define debug(var) cout << "[" << #var << "] " << var << endl
const ll mod = 1000000007;


int main(){
    ll n, m;
    cin >> n >> m;
    
    vector<ll> x(n);
    vector<ll> y(n);
    vector<ll> z(n);

    rep(i, n) {
        cin >> x[i];
        cin >> y[i];
        cin >> z[i];
    }
    ll ans = 0;

    rep(i, 1LL<<3) {
        vector<bool> flg(3);
        vector<ll> score(n);
        rep(j, 3) {
            flg[j] = ((i>>j & 1)==1);
        }
        rep(j, n) {
            ll now = 0;
            if (flg[0]) now += x[j];
            else now -= x[j];
            if (flg[1]) now += y[j];
            else now -= y[j];
            if (flg[2]) now += z[j];
            else now -= z[j];
            score[j] = now;
        }
        ll sum = 0;
        sort(score.begin(), score.end());
        reverse(score.begin(), score.end());
        rep(j, m) {
            sum += score[j];
        }
        ans = max(ans, sum);
    }
    
    
    
    cout << ans << endl;
    return 0;
}
