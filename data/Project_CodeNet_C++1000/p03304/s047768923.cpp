#include <bits/stdc++.h>
using namespace std;
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20)
#define int long long
#define double long double
const int INF = 1e18, MOD = 2019;

signed main() {
    INCANT;
    double n, m, d;
    cin>>n>>m>>d;
    if (d == 0) {
        cout<<(m - 1) / n<<endl;
    } else {
        cout<<(m - 1) * 2 * (n - d) / n / n<<endl;
    }
}