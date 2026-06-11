#include <bits/stdc++.h>
using namespace std;

void chmin (int &a, int b) {
    if (a > b) a = b;
}

int main() {
    int n;
    cin >> n;
    vector<int> t(110), s(110), v(110);
    for (int i = 1; i <= n; i++) {
        cin >> t[i]; t[i] *= 2;
        s[i + 1] = s[i] + t[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> v[i]; v[i] *= 2;
    }
    s[n + 2] = s[n + 1];
    
    const int time = s[n + 1];
    vector<int> p(time + 1);
    for (int x = 0; x <= time; x++) {
        int res = numeric_limits<int>::max();
        for (int j = 0; j < n + 2; j++) {
            const int l = s[j], r = l + t[j];
            if (x < l) chmin(res, v[j] + (l - x));
            else if (x < r) chmin(res, v[j]);
            else chmin(res, v[j] + (x - r));
        }
        p[x] = res;
    }
    
    double ans = 0;
    for (int i = 0; i < time; i++) {
        double res = (double)(p[i] + p[i + 1]) / 2.0;
        ans += res;
    }
    
    cout << fixed << setprecision(5) << ans / 4.0 << '\n';
    return 0;
}