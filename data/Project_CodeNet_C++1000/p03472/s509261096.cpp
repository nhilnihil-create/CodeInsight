/**
*    created: 21.06.2020 01:01:59
**/
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(a) (a).begin(),(a).end()
#define mod 1000000007
#define pi acos(-1.0)
using namespace std;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, h;
    cin >> n >> h;
    vector<int> a(n);
    vector<int> b(n);
    rep(i,n) cin >> a[i] >> b[i];
    sort(all(a));
    sort(all(b));
    int cnt = 0;
    int dam = 0;
    int t = lower_bound(all(b),a[n-1]) - b.begin();
    for (int i = n - 1; i >= t; i--) {
        dam += b[i];
        cnt++;
        if (dam >= h) {
            cout << cnt << endl;
            return 0;
        }
    }

    if ((h - dam) % a[n-1] == 0) cnt += (h - dam) / a[n-1];
    else cnt += (h - dam) / a[n-1] + 1;
    cout << cnt << endl;
    return 0;
}