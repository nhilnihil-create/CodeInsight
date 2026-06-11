#include <bits/stdc++.h>
#define MP make_pair
#define fi first
#define se second
#define sz(x) (int)(x).size()
//#define Local
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 2e5 + 5;

int n;
int a[N];
ll sum[N];

ll Get(int l, int r, int m) {
    return abs(sum[r] - sum[m] - sum[m] + sum[l - 1]);
}

void run() {
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    int j = 1, k = 3;
    ll ans = 1e18;
    for(int i = 2; i <= n - 1; i++) {
        while(j < i - 1 && Get(1, i, j) > Get(1, i, j + 1)) ++j;
        while(k < n - 1 && Get(i + 1, n, k) > Get(i + 1, n, k + 1)) ++k;
        ll mx = max(sum[i] - sum[j], max(sum[j], max(sum[n] - sum[k], sum[k] - sum[i])));
        ll mn = min(sum[i] - sum[j], min(sum[j], min(sum[n] - sum[k], sum[k] - sum[i])));
//        cout << j << ' ' << i << ' ' << k << '\n';
        ans = min(ans, mx - mn);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
#ifdef Local
    freopen("../input.in", "r", stdin);
    freopen("../output.out", "w", stdout);
#endif
    while(cin >> n) run();
    return 0;
}
