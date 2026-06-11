#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll mdif(ll a, ll b, ll c, ll d) {
    ll ma = max(max(a, b), max(c, d));
    ll mi = min(min(a, b), min(c, d));
    return ma - mi;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int j = 0, k = 1;
    ll s1 = a[0], s2 = 0, s3 = a[1], s4 = 0;
    for (int i = 2; i < n; i++) {
        s4 += a[i];
    }
    long long ans = mdif(s1, s2, s3, s4);
    for (int i = 1; i < n - 2; i++) {
        s2 += a[i];
        s3 -= a[i];
        while (j < i - 1 && s1 < s2) {
            j++;
            s1 += a[j];
            s2 -= a[j];
        }
        while (k < n - 1 && s3 < s4) {
            k++;
            s3 += a[k];
            s4 -= a[k];
        }

        ans = min(ans, mdif(s1, s2, s3, s4));
        if (j > 0) {
            ans = min(ans, mdif(s1 - a[j], s2 + a[j], s3, s4));
        }
        if (k > i + 1) {
            ans = min(ans, mdif(s1, s2, s3 - a[k], s4 + a[k]));
        }
        if (j > 0 && k > i + 1) {
            ans = min(ans, mdif(s1 - a[j], s2 + a[j], s3 - a[k], s4 + a[k]));
        }
    }

    cout << ans << endl;

    return 0;
}
