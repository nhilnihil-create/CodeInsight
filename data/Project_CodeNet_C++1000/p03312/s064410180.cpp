#include<bits/stdc++.h>
using namespace std;
#define N 200005
typedef long long ll;
ll n, a[N], s[N], re = 1e9;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    s[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    ll i, j, k, s1, s2, s3, s4, sma, smi, re=1e9;
    i = 1;
    j = 2;
    k = 3;
    s1 = a[1];
    s2 = a[2];
    s3 = a[3];
    s4 = s[n] - s1 - s2 - s3;
    sma = max({s1, s2, s3, s4});
    smi = min({s1, s2, s3, s4});
    re = sma - smi;
    while (j < n - 1) {
        while ( i < j - 1 && s1 + a[i + 1] <= s2 - a[i + 1]) {
            s1 += a[i + 1];
            s2 -= a[i + 1];
            ++i;
        }
        if (s2 - s1 > s1 + 2 * a[i + 1] - s2) {
            ++i;
            s1 += a[i];
            s2 -= a[i];
        }
        while (k < n - 1 && s3 + a[k + 1] <= s4 - a[k + 1]) {
            s3 += a[k + 1];
            s4 -= a[k + 1];
            ++k;
        }
        if (s4 - s3 > s3 + 2 * a[k + 1] - s4) {
            s3 += a[k + 1];
            s4 -= a[k + 1];
            ++k;
        }
        sma = max({s1, s2, s3, s4});
        smi = min({s1, s2, s3, s4});
        re = min(re, sma - smi);
        ++j;
        s2 += a[j];
        s3 -= a[j];
    }
    cout << re;
    return 0;
}
