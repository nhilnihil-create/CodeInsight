#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int(i) = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define pb push_back
#define MP(a, b) make_pair((a), (b))
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<int> L(M), R(M);
    rep(i, M) { cin >> L[i] >> R[i]; }

    vector<vector<int>> a(N, vector<int>(N));
    rep(i, M) { a[R[i] - 1][L[i] - 1]++; }

    vector<vector<int>> s(N + 1, vector<int>(N + 1));
    rep(i, N) rep(j, N) {
        s[i + 1][j + 1] = s[i][j + 1] + s[i + 1][j] - s[i][j] + a[i][j];
    }
    rep(i, Q) {
        int p, q;
        cin >> p >> q;
        cout << s[q][N] - s[q][p - 1] << '\n';
    }
    return 0;
}