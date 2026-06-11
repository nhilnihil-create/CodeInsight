 #pragma GCC optimize("O3")
 #pragma GCC optimize("unroll-loops")
 #pragma GCC optimize("fast-math")
#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;

#define int long long
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

void accell() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
}
const int N = 1e5 + 5;

int dp[N][4];

signed main() {
    accell();
    int n, a, b;
    cin >> n >> a >> b;
    if ((b - a) % 2 == 0)
        cout << "Alice";
    else
        cout << "Borys";
    return 0;
}
