#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647
// MAX O(n) 10^18

int main() {
    int D, N;
    cin >> D >> N;

    int ans;
    if (N == 100) {
        if (D == 0) ans = 101;
        if (D == 1) ans = 10100;
        if (D == 2) ans = 1010000;
    } else {
        ans = pow(100, D) * N;
    }

    cout << ans << endl;
    return 0;
}
