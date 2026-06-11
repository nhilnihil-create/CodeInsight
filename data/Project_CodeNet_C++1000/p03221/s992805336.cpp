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
    vector<ll> ans(m);
    vector<vector<P>> py(n);
    int p, y;
    rep(i, m) {
        cin >> p >> y;--p;
        py[p].push_back(P(i, y));
    }
    rep(i, n) {
        if (py[i].size() > 0){
            sort(py[i].begin(), py[i].end(),
            [](const P& x, const P& y){return x.second < y.second;}
            );
        }
        rep(j, py[i].size()){
            // cout << i << j << endl;
            ans[py[i][j].first] = (i+1)*1000'000 + j+1;
        }
    }

    rep(i, m){
        printf("%012ld\n", ans[i]);
    }
    return 0;
}