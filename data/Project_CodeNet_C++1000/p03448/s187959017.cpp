#include <bits/stdc++.h>
using namespace std;
#define repl(i, l, r) for (ll i = (l); i < (r); i++)
#define rep(i, n) repl(i, 0, n)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define CST(x) cout << fixed << setprecision(x)
using ll = long long;
const ll MOD = 1000000007;
const int inf = 1e9 + 10;
const ll INF = 4e18 + 10;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int A, B, C, X;
    cin >> A >> B >> C >> X;
    int sum = 0;

    for (int i = 0; i <= A; i++) {
        for (int j = 0; j <= B; j++) {
            for (int k =0; k <= C; k++) {
                if (10 * i + 2 * j + k == X / 50) sum++;
            }
        }
    }
    cout << sum << endl;
    
    return 0;
}
