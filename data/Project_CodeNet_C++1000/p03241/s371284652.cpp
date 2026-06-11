#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
 
int main() {
    int n, m;
    cin >> n >> m;
    int ans = 1;
    for (int i = 1; i*i <= m; i++) {
        if (m % i == 0) {
            if (i <= m / n) ans = max(ans, i);
            if (i >= n) ans = max(ans, m / i);
        }
    }
    cout << ans << endl;
    return 0;
}