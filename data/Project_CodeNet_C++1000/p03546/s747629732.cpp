#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define PI acos(-1)
#define Mod (int)1000000007
#define INFTY (int)INT_MAX
#define Rep(i, n) for (int i = 0; i < (int)(n); i++)
#define BitRep(i, n) for (int i = 0; i < (int)(1 << n); i++)
#define All(vec) vec.begin(), vec.end()
#define Sum(vec) accumulate(vec.begin(), vec.end(), 0)
#define Sort(vec) sort(vec.begin(), vec.end())
#define Reverse(vec) reverse(vec.begin(), vec.end())
#define Count(vec, x) count(vec.begin(), vec.end(), x)
#define Next_permutation(vec) next_permutation(vec.begin(), vec.end())
#define Find(S, s) S.find(s) != string::npos

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> c(10, vector<int>(10));
    Rep(i, 10) {
        Rep(j, 10) {
            cin >> c[i][j];
        }
    }
    Rep(k, 10) {
        Rep(i, 10) {
            Rep(j, 10) {
                c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
            }
        }
    }
    int ans = 0;
    Rep(i, H) {
        Rep(j, W) {
            int a;
            cin >> a;
            if (a == -1) continue;
            else ans += c[a][1];
        }
    }
    cout << ans << endl;
    return 0;
}