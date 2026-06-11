#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, H;
    cin >> N >> H;
    vector<ll> a(N), b(N);
    REP(i, N) cin >> a[i] >> b[i];
    int x = *max_element(ALL(a));
    sort(ALL(b), greater<int>());
    ll sum = 0;
    int ans = 0;
    REP(i, N) {
        if (b[i] < x) break;
        sum += b[i];
        ans++;
        if (sum >= H) {
            cout << ans << endl;
            return 0;
        }
    }
    ans += (H - sum + x - 1) / x;
    cout << ans << endl;

}