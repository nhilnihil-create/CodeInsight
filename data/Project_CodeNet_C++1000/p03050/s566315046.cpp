#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pint = pair<int, int>;
using vi = vector<int>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define endl "\n"

constexpr int MOD = 1000000007;
const int INF = 1 << 30;

int main() {
    lint n;
    cin >> n;

    lint res = 0;

    lint i = 1;
    while (i * i <= n) {
        lint m = (n - i);
        if (m % i != 0) { i++; continue; }
        m /= i;
        if (i >= m) { i++; continue; }
        res += m;
        i++;
    }

    cout << res << endl;
    return 0;
}
