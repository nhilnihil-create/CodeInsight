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
    lint x, y;
    cin >> x >> y;

    if (x % y == 0) {
        cout << "-1" << endl;
        exit(0);
    }

    cout << x << endl;
    return 0;
}
