#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;

int main() {
    int64_t K, A, B;
    cin >> K >> A >> B;
    int64_t ans = K + 1;
    int64_t C = B - A;
    int64_t n = (K - A + 1) / 2;
    int64_t tmp = C * n + A + (K - A + 1) % 2;
    if(C > 1 && K >= A - 1) ans = max(ans, tmp);
    cout << ans << '\n';
    return 0;
}
