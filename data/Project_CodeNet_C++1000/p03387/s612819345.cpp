#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<map>
#include<set>
#include<iomanip>

using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int INF = numeric_limits<int>::max();
const ll LLINF = numeric_limits<ll>::max();
const double PI = acos(-1.0);

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, a, n) for (int i = a; i <= (n); ++i)

int main() {
    vector<int> A(3); rep(i, 3) cin >> A[i];

    // 降順にソート
    sort(A.rbegin(), A.rend());

    // 3 * A[0] にするの必要な数
    int rest = A[0] - A[1] + A[0] - A[2];

    int ans = 0;
    if (rest & 1) {
        // 奇数の場合
        ans = (rest + 3) / 2;
    } else {
        // 偶数の場合
        ans = rest / 2;
    }

    cout << ans << endl;
    return 0;
}
