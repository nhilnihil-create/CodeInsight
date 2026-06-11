#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;
using lint = int64_t;

int main() {
    int N;
    cin >> N;
    vector<vector<char>> S(N, vector<char>(N));
    rep(i, N) rep(j, N) cin >> S[i][j];
    int ans = 0;
    vector<vector<char>> T(N, vector<char>(N));
    rep(A, N) {
        rep(i, N) rep(j, N) T[i][j] = S[(i + A) % N][j];
        bool judge = true;
        rep(i, N) rep(j, N) {
            if (T[i][j] != T[j][i]) judge = false;
        }
        if (judge) ans += N;
    }
    cout << ans << "\n";
    return 0;
}
