#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using Vi = vector<int>;
using Vl = vector<ll>;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

constexpr int I_INF = numeric_limits<int>::max();
constexpr ll L_INF = numeric_limits<ll>::max();

//==================================

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<string> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    int ans = 0;
    for (int d = 0; d < N; d++) {
        bool ok = true;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int x1, x2, y1, y2;
                x1 = (i + d) % N;
                x2 = (j + d) % N;
                y1 = j;
                y2 = i;
                if (S[x1][y1] != S[x2][y2]) {
                    ok = false;
                    break;
                }
            }
            if (!ok) break;
        }
        if (ok) {
            ans += N;
        }
    }

    cout << ans << endl;

    return 0;
}