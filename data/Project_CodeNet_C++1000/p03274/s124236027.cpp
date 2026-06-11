#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    rep(i, n) cin >> x[i];
    int ans = MOD;
    for (int i = 0; i <= n - k; i++)
    {
        ans = min(ans, x[i + k - 1] - x[i] + abs(x[i]));
        ans = min(ans, x[i + k - 1] - x[i] + abs(x[i + k - 1]));
    }
    cout << ans << endl;
}