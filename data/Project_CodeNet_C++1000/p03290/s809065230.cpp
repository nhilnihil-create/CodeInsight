#include <bits/stdc++.h>
using namespace std;

void solve() {
    int d, g;
    cin >> d >> g;
    vector<int> p(d), c(g);
    int ans = 1e5;
    for (int i = 0; i < d; i++) {
        cin >> p[i] >> c[i];
    }
    for (int i = 0; i <= (1 << d); i++) {

        long long sum = 0;
        int s = 0;
        for (int j = d - 1; j >= 0; j--) {
            if(i & (1 << j)) {
                int cnt = 0;
                while(cnt < p[j] && sum < g) {
                    sum += (j + 1) * 100;
                    cnt++;
                    s++;
                }
                if(cnt >= p[j]) {
                    sum += c[j];
                }

                if(sum >= g) {
                    break;
                }
            }
        }
        if(sum >= g)
            ans = min(ans , s);
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
