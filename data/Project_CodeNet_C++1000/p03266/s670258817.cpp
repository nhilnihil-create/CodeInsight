#include "bits/stdc++.h"
#define MOD 1000000007
#define inf 0x3f3f3f3f3f3f3f3f
#define pi acos(-1.0)
#define ri register int
#define int long long
#ifdef ONLINE_JUDGE
const int maxn = 3e5 + 10;
#else
const int maxn = 1e3 + 10;
#endif
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    int ans = (N / K) * (N / K) * (N / K);
    if (~K & 1) {
        int tmp = (N + K / 2) / K;
        ans += tmp * tmp * tmp;
    }
    cout << ans << endl;
    return 0;
}