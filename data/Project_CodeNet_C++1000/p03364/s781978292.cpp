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
    int N;
    cin >> N;
    vector<vector<char>> S(2 * N, vector<char>(2 * N));
    rep(i, N) {
        rep(j, N) {
            char c;
            cin >> c;
            S[i][j] = S[i + N][j] = S[i][j + N] = S[i + N][j + N] = c;
        }
    }

    int res = 0;
    for(int sy = 0; sy < N; sy++) {
        int ok = 1;
        for(int i = 0; i < N; i++) {
            for(int j = i + 1; j < N; j++) {
                if(S[sy + i][j] != S[sy + j][i])
                    ok = 0;
            }
        }
        if(ok) {
            res += N - sy;
        }
    }
    for(int sx = 1; sx < N; sx++) {
        int ok = 1;
        for(int i = 0; i < N; i++) {
            for(int j = i + 1; j < N; j++) {
                if(S[i][sx + j] != S[j][sx + i])
                    ok = 0;
            }
        }
        if(ok) {
            res += N - sx;
        }
    }
    cout << res << endl;
    return 0;
}