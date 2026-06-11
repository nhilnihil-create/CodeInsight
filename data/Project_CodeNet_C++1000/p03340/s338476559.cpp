#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define sz(a) (int)a.size()
#define int long long

using namespace std;

int a[200010];
int sl[200010];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i= 0; i < n; i++) {
        cin >> a[i];
    }
    int cnt = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] == 0)
            cnt++;
        else
            cnt = 0;
        sl[i] = cnt;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int s1 = 0, s2 = 0;
        int k = i;
        while (k < n) {
            if (sl[k] != 0) {
                if (s1 == s2) {
                    ans += sl[k];
                }
                k += sl[k];
            }
            if (k >= n)
                break;
            s1 += a[k];
            s2 ^= a[k];
            if (s1 == s2)
                ans++;
            if (s1 > s2)
                break;
            k++;
        }
    }
    cout << ans << endl;
    return 0;
}
