#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define MOD 1000000007;
#define MOD2 998244353;
#define INF ((1<<30)-1);
#define LINF (1LL<<60);
#define EPS (1e-10);
typedef long long Int;
typedef pair<Int, Int> P;

int n, h, w;

int main() {
    cin >> n >> h >> w;
    int ans = (n - h + 1) * (n - w + 1);
    cout << ans << endl;
}