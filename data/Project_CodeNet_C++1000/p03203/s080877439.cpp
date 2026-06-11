#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
using namespace std;
#define FOR(i,j,k) for(int (i)=(j);(i)<(int)(k);++(i))
#define rep(i,j) FOR(i,0,j)
#define each(x,y) for(auto &(x):(y))
#define mp make_pair
#define MT make_tuple
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<(x)<<endl
#define smax(x,y) (x)=max((x),(y))
#define smin(x,y) (x)=min((x),(y))
#define MEM(x,y) memset((x),(y),sizeof (x))
#define sz(x) (int)(x).size()
#define RT return
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

void solve() {
    int W, H, N;
    cin >> W >> H >> N;

    vector<set<int>> X(H + 1);
    rep(i, N) {
        int x, y;
        cin >> x >> y;
        X[y].insert(x);
    }

    int ans = W;
    for (int y = 1, x = 1; y <= H; ++y) {
        if (y != 1) {
            x++;
        }
        while (1) {
            auto it = X[y].lower_bound(x);
            if (it != X[y].end() && *it == x) {
                ++x;
            } else {
                break;
            }
        }
        auto it = X[y].lower_bound(x);
        if (it != X[y].end()) {
            smin(ans, *it - 1);
        }
    }
    cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(15);
	solve();
	return 0;
}