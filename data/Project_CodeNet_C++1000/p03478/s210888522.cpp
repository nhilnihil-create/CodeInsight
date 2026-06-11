#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int count_digits(int x) {
    int count = 0;
    while (x) {
        count += x % 10;
        x /= 10;
    }
    return count;
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    int ans = 0;
    for (int i=1; i<=n; i++) {
        int count = count_digits(i);
        if (count >= a && count <= b) ans += i;
    }
    cout << ans << endl;
    return 0;
}