#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
using ld = long double;
const int MOD = 1e9+7;


int main() {
    int n; cin >> n;
    V<int> a(n + 1);
    a[0] = 0;
    for(int i = 1; i <= n; i++) cin >> a[i];
    a.push_back(0);

    V<int> sub(n + 1);
    for(int i = 0; i <= n; i++){
        sub[i] = abs(a[i + 1] - a[i]);
    }

    int sum = accumulate(ALL(sub), 0);

    for(int i = 1; i <= n; i++){
        int tmp1 = sub[i] + sub[i - 1];
        int tmp2 = abs(a[i + 1] - a[i - 1]);
        cout << sum - tmp1 + tmp2 << endl;
    }

    return 0;
}
