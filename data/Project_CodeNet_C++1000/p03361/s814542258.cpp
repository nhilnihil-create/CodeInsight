#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<map>
#include<set>
#include<iomanip>

using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int MAX = 1e9;
const ll LLMAX = 1e18;
const int INF = numeric_limits<int>::max();
const ll LLINF = numeric_limits<ll>::max();
const double PI = acos(-1.0);

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, a, n) for (int i = a; i <= (n); ++i)

int main() {
    int H, W; cin >> H >> W;
    vector<string> S(H); rep(i, H) cin >> S[i];

    const int di[4] = {-1, 0, 0, 1};
    const int dj[4] = {0, -1, 1, 0};

    int all_ok = true;
    rep(i, H) {
        rep(j, W) {
            if (S[i][j] == '#') {
                int ok = false;
                rep(k, 4) {
                    int ni = i + di[k];
                    int nj = j + dj[k];
                    if (ni < 0 || ni >= H) continue;
                    if (nj < 0 || nj >= W) continue;
                    if (S[ni][nj] == '#') ok = true;
                }
                if (!ok) all_ok = false;
            }            
        }
    }

    if (all_ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
