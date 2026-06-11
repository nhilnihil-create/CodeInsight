#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const int inf = 1e9;
double pi = 3.14159265359;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, b, a) for (int i = a - 1; i >= b; i--)
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dxx[8] = {1, 1, 1, 0, 0, -1, -1, -1}, dyy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    ll n;
    cin >> n;
    ll ans = 0;
    for (ll b = 1; b * b <= n; b++) {
        if (n % b == 0) {
            ll m = n / b;
            if (m - 1 > b) {
                ans += m - 1;
                // cout << m - 1 << "\n";
            }
        }
    }
    cout << ans << "\n";
}