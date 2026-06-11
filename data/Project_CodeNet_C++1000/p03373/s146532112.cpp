#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int ans = 1001001001;
    int ac, bc, cc;
    for (int ab_cnt = 0; ab_cnt <= max(x, y)*2; ab_cnt+=2) {
        int sum_price = ab_cnt * c + max((x - ab_cnt/2), 0) * a + max((y - ab_cnt/2), 0) * b;
        ans = min(sum_price, ans);
    }
    cout << ans << endl;
}