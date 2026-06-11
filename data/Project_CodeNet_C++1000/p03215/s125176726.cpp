#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;


int main(void) {
    int n, k, i, j;
    ll a[1003] = {}, ans = 0;
    vector<ll> lv;

    cin >> n >> k;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (i = 1; i <= n; i++) {
        a[i] += a[i - 1];
    }

    for (i = 0; i < n; i++) for (j = i + 1; j <= n; j++) {
        lv.push_back(a[j] - a[i]);
    }

    sort(lv.begin(), lv.end(), greater<ll>());

    while (lv.size() >= k) {

        int t1, t2, mt;
        ll m1, m2, r;
        vector<ll> y;

        m1 = lv[0];
        m2 = lv[k - 1];

        if (m1 <= 1) {
            if (m2 == 1) ans++;
            break;
        }

        t1 = t2 = 0;
        while (m1 > 1) {
            m1 /= 2;
            t1++;
        }
        while (m2 > 1) {
            m2 /= 2;
            t2++;
        }

        mt = max(t1, t2);

        r = 1;
        for (i = 0; i < mt; i++) {
            r *= 2;
        }

        if (t1 == t2) {
            ans += r;
            for (i = 0; i < lv.size(); i++) {
                if (lv[i] < r) break;
                y.push_back(lv[i] - r);
            }
        }
        else {
            for (i = 0; i < lv.size(); i++) {
                if (lv[i] != r) y.push_back(lv[i] % r);
            }
        }

        lv = y;

        sort(lv.begin(), lv.end(), greater<ll>());

    }

    printf("%lld\n", ans);

    return 0;
}