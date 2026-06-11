#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main () {
    int N, H;
    cin >> N >> H;
    long long katana[100000];
    for (int i = 0; i < N; i++) {
        long long a, b;
        cin >> a >> b;
        katana[i] = a + (b << 30);
    }
    sort(katana, katana + N);
    int c = 0;
    int ans = 0;
    for (int i = N - 1; i >= 0; i--) {
        long long k = katana[i];
        int b = (int)(k >> 30);
        if (b < c) {
            break;
        }
        H -= b;
        ans++;
        if (H <= 0) {
            c = 0;
            break;
        }
        int a = (int)(k & (1 << 30) - 1);
        c = max(c, a);
    }
    if (c > 0) {
        ans += (H - 1) / c + 1;
    }
    cout << ans << endl;
    return 0;
}
