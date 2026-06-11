#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    double n, k, ans = 0;
    cin >> n >> k;
    rep(i, n) {
        int cnt = 0, num = i + 1;
        double tmp = 1;
        while(num < k) {
            cnt++;
            num *= 2;
            tmp *= 0.5;
        }
        tmp /= n;
        ans += tmp;
    }
    cout << fixed << setprecision(15) << ans << endl;
    return 0;
}