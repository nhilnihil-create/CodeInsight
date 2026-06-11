#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fo(i, n) for(int i = 1; i <= n; ++i)
typedef long long ll;

const int N = 1000300;
const int mod =  998244353;
const ll inf = 1e18;
int n;
int x[N], y[N];
int used[N];
ll ans = 0;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    fo(i, n) cin >> x[i] >> y[i];
    sort(x, x + n + 1); reverse(x, x + n + 1);
    sort(y, y + n + 1);
    for(int i = 0; i <= n; ++i) ans += max(0, 2 * (x[i] - y[i]));
    cout << ans;

    return 0;
}