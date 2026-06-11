#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

const int INF = 1000000007;
const ll INFLL = 1000000000000000007;

#define st first
#define nd second
#define pb push_back
#define _boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// ***************************** CODE ***************************** //

const int MAX = 3e3 + 7;
const int mod = 1e9 + 7;

int dp[MAX][MAX], pre[MAX][MAX];

void add(int& a, int b)
{
    a += b;
    if(a >= mod)
        a -= mod;
}

int sub(int a, int b)
{
    a -= b;
    if(a < 0)
        a += mod;
    return a;
}

int main() {
    _boost;

    int n;  string s;
    cin >> n >> s;

    dp[1][1] = 1;
    for(int i = 2; i <= n; i++)
    {
        for(int j = 1; j < i; j++)
            pre[i-1][j] = (pre[i-1][j-1] + dp[i-1][j]) % mod;

        for(int j = 1; j <= i; j++)
        {
            int l, r;
            if(s[i-2] == '<')
                l = 1, r = j - 1;
            else
                l = j, r = i - 1;
            if(l <= r)
                add(dp[i][j], sub(pre[i-1][r], pre[i-1][l-1]));
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++)
        add(ans, dp[n][i]);

    cout << ans;

    return 0;
}
