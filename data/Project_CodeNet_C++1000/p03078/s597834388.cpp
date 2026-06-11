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

    vector<Int> d;
    for (int i = 0; i < x; i++) {
        for (int k = 0; k < y; k++) {
            d.push_back(a[i] + b[k]);
        }
    }
    sort(d.begin(), d.end(), greater<>());
    sort(c.begin(), c.end(), greater<>());

    vector<Int> ans;
    int ro = min(3000, x * y);
    for (int i = 0; i < ro; i++) {
        for (int k = 0; k < z; k++) {
            ans.push_back(d[i] + c[k]);
        }
    }

    sort(ans.begin(), ans.end(), greater<>());
    for (int i = 0; i < K; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
