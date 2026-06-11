#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    
    int p[100];
    for (int i = 0; i < 100; i++) {
        p[i] = 0;
    }

    for (int x = 2; x <= n; x++) {
        int nx = x;
        int d = 2;
        while (nx > 1) {
            if (nx % d == 0) {
                nx /= d;
                p[d]++;
            } else {
                d++;
            }
        }
    }

    int ans = 0;
    for (int i = 2; i < 100; i++) {
        if (p[i] >= 74) ans++;
    }
    int s = 0, t = 0;
    for (int i = 2; i < 100; i++) {
        if (p[i] >= 24) s++;
        if (p[i] >= 2) t++;
    }
    ans += s * (t - 1);
    s = 0;
    t = 0;
    for (int i = 2; i < 100; i++) {
        if (p[i] >= 14) s++;
        if (p[i] >= 4) t++;
    }
    ans += s * (t - 1);
    s = 0;
    t = 0;
    for (int i = 0; i < 100; i++) {
        if (p[i] >= 4) s++;
        if (p[i] >= 2) t++;
    }
    ans += (s * (s - 1) / 2) * (t - 2);

    cout << ans << endl;
    return 0;
}