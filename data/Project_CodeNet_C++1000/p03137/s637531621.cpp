#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> VI;
typedef vector<VI> VVI;
typedef pair<ll, ll> P;
#define FOR(i,a,b) for(ll i=ll(a);i<ll(b);++i)
#define rep(i,n)  FOR(i,0,n)
#define PRINT(V) for (auto v : (V)) cout << v << " "
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const ll INF = numeric_limits<ll>::max();
int main()
{
    int n, m; cin >> n >> m;
    VI x(m); rep(i, m) cin >> x[i];
    if (n >= m) {
        cout << 0 << endl;
        return 0;
    }
    sort(ALL(x));

    VI diff(m-1);
    rep(i, m-1){
        diff[i] = x[i+1] - x[i];
    }
    sort(diff.begin(), diff.end(), greater<ll>());
    //PRINT(diff);
    ll ans = *max_element(ALL(x)) - *min_element(ALL(x));

    rep(i, n-1) ans -= diff[i];
    cout << ans <<endl;
    return 0;
}