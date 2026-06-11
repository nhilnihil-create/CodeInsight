#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define dump(x) cout << x << endl
typedef int64_t Int;

using namespace std;
using Graph = vector<vector<Int>>;

const double pi = M_PI;
const Int MOD = 1000000007;

int main() {
    int x, y, z, K;
    cin >> x >> y >> z >> K;
    vector<Int> a(x), b(y), c(z);

    for (int i = 0; i < x; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < y; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < z; i++) {
        cin >> c[i];
    }
    sort(a.begin(), a.end(), greater<>());
    sort(b.begin(), b.end(), greater<>());
    sort(c.begin(), c.end(), greater<>());

    vector<Int> ans;
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= y; j++) {
            for (int k = 1; k <= z; k++) {
                if (i * j * k <= K) {
                    ans.push_back(a[i - 1] + b[j - 1] + c[k - 1]);
                } else {
                    break;
                }
            }
        }
    }

    sort(ans.begin(), ans.end(), greater<>());
    for (int i = 0; i < K; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
