#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
const int INF = 1e9;

int main() {
    int n;
    cin >> n;

    string ans = "";
    if (n == 0)
        ans = "0";
    else {
        while (n != 0) {
            int d = (n % -2 + 2) % 2;
            ans += char('0' + d);
            n -= d;
            n /= -2;
        }
    }

    reverse(ans.begin(), ans.end());

    cout << ans << endl;

    return 0;
}