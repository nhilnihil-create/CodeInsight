#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
using namespace std;

int main() {
    int N;
    ll x;
    cin >> N >> x;
    ll a[110];
    rep(i, N) { cin >> a[i]; }
    sort(a, a + N);
    int ans = 0;
    ll total = 0;
    rep(i, N) {
        total += a[i];
        if (total > x) break;
        ans++;
    }
    if (total < x) ans--;
    cout << ans << endl;
}