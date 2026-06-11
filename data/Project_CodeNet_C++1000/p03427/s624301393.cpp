#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i >= a; i--)
#define int ll
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int Cnt(int n) {
    int cnt = 0;
    while (n) {
        n /= 10;
        cnt++;
    }
    return cnt;
}

signed main() {
    int n;
    cin >> n;
    int cnt = Cnt(n);
    int ans = (cnt - 1) * 9 + n / (int)pow(10, cnt - 1) % 10 - 1;
    int sum = 0;
    rep(i, 0, cnt) { sum += n / (int)pow(10, i) % 10; }
    // cout << sum << "\n";
    cout << max(ans, sum) << "\n";
}