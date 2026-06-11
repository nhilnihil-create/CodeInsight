#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

int a[2][110];
int b[110];

int main() {
    int n;
    cin >> n;
    rep(i,2) {
        rep(j,n) {
            int x;
            cin >> x;
            a[i][j+1] = a[i][j] + x;
        }
    }
    int ans = 0;
    rep(i,n) {
        ans = max(ans, a[0][i+1] + a[1][n] - a[1][i]);
    }
    cout << ans << endl;
}