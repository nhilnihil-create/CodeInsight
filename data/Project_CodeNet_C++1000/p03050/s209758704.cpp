//#include "atcoder.h"
//#include "math.h"
//#include "prime.h"
//#include "countmap.h"
//#include "bigint.h"
//#include <bits/stdc++.h>
//using namespace std;
//using Int = long long;
//#define PUTS(x) cout << (x) << endl;
//#define rep(i, n) for (int i = 0, i##_len = (int)(n); i < i##_len; i++)
//#define reps(i, n) for (int i = 1, i##_len = (int)(n); i <= i##_len; i++)
//#define PB push_back
//#define MP make_pair
//#define MT make_tuple
//#define F first
//#define S second
//#define ALL(v) (v).begin(), (v).end()
//#define SZ(x) ((int)(x).size())
//#define LEN(x) ((int)(x).length())
//#define MOD 1000000007

// #include <bits/stdc++.h>
// using namespace std;
// using Int = long long;
// #define rep(i, n) for (int i = 0, i##_len = (int)(n); i < i##_len; i++)
// #define reps(i, n) for (int i = 1, i##_len = (int)(n); i <= i##_len; i++)
// #define ALL(v) (v).begin(), (v).end()
// #define PUTS(x) cout << (x) << endl;
// #define PB push_back
// #define MP make_pair
// #define F first
// #define S second
// vector<Int> IntsIn(int n) {
//     auto v = vector<Int>(0);
//     for (int i = 0; i < n; i++) {
//         Int a;
//         cin >> a;
//         v.push_back(a);
//     }
//     return v;
// }

// #define INF 100000000000LL

#include <bits/stdc++.h>
using Int = long long;
using namespace std;
int main() {
    Int n;
    cin >> n;
    Int ans = 0LL;
    for (Int i = 1; i * i < n; i++) {
        if (n % i == 0) {
            auto j = n / i;
            if (j - i >= 2) {
                ans += j - 1;
            }
        }
    }
    cout << ans << endl;
}
