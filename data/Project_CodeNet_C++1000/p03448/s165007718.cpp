#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll A, B, C, X;
int main() {
    cin >> A >> B >> C >> X;

    ll ans = 0;
    // 500 円 Aまい
    for (int i = 0; i <= A; i++) {
        for (int j = 0; j <= B; j++) {
            for (int k = 0; k <= C; k++) {
                if (X == i * 500 + j * 100 + k * 50) {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
}