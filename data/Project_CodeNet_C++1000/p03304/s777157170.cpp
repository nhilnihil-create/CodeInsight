#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 1e5 + 5;
const int INF = 1001001001;
const int MOD = 1e9 + 7;

int main(){
    int n, m, d;
    cin >> n >> m >> d;

    double ans = 0;

    if (d == 0) {
        rep(i, m - 1) {
            ans += (double)n / n / n;
        }
    } else {
        rep(i, m - 1) {
            ans += (double)2 * (n - d) / n / n;
        }
    }

    printf("%.10f\n", ans);
}