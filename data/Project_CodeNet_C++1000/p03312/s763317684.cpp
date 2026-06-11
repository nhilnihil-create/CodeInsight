#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n), sum(n+1, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum[i+1] = sum[i] + a[i];
    }
    
    auto bs = [&](int i)->long long {
        int l = 0, r = i-1;
        long long value = sum[i] / 2;
        while (abs(l - r) > 1) {
            int m = (l + r) / 2;
            if (sum[m] < value) l = m;
            else r = m;
        }
        long long vl = sum[l], vr = sum[r];
        long long nl = sum[i] - sum[l], nr = sum[i] - sum[r];
        if (abs(nl - vl) > abs(nr - vr)) return vr;
        else return vl;
    };
    auto bss = [&](int i) {
        int l = i+1, r = n-1;
        long long value = sum[i] + (sum[n] - sum[i]) / 2;
        while (abs(l - r) > 1) {
            int m = (l + r) / 2;
            if (sum[m] < value) l = m;
            else r = m;
        }
        long long vl = sum[l] - sum[i], vr = sum[r] - sum[i];
        long long nl = sum[n] - sum[l], nr = sum[n] - sum[r];
        if (abs(nl - vl) > abs(nr - vr)) return vr;
        else return vl;
    };
    
    long long ans = INF;
    for (int i = 2; i < n-1; i++) {
        long long b = bs(i), c = sum[i] - b;
        long long d = bss(i), e = sum[n] - (b + c + d);
        long long f = max({b, c, d, e}) - min({b, c, d, e});
        if (ans > f) ans = f;
    }
    
    cout << ans << endl;
    return 0;
}