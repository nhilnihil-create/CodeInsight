#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

char s[200105];
int cur, a[200105], dp[1 << 26];

int main()
{
    ios_base::sync_with_stdio(false);

    for (int mask = 1 << 26; --mask; )
        dp[mask] = 1e9;

    cin >> s;
    for (int i = 0; s[i]; ++i) {
        cur ^= (1 << (s[i] - 'a'));
        int mn = 1e9;
        for (int j = 1 << 25; j; j >>= 1)
            mn = min(mn, dp[cur ^ j]);
        dp[cur] = min(dp[cur], mn + 1);
    }

    cout << max(1, dp[cur]) << endl;

    return 0;
}
