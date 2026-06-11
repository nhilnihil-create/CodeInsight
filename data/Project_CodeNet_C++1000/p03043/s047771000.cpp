/**
*    created: 21.06.2020 23:32:28
**/
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pcnt(bit) __builtin_popcount(bit)
#define mod 1000000007
#define pi acos(-1.0)
using namespace std;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    //最後にnで割る
    long double sum = 0;
    cout << fixed << setprecision(20);
    for (int i = 1; i <= n; i++) {
        if (i >= k) {
          sum += 1.00000000000000;
          continue;
        }
        int t = 1;
        int f = i;
        while(f < k) {
            f *= 2;
            t *= 2;
        }
        sum += 1.000000000000000000 / t;
    }
    cout << sum / n << endl;
    return 0;
}