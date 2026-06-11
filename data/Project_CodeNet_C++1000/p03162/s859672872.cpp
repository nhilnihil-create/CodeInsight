#include <bits/stdc++.h>
using namespace std;
#define ft              first
#define sd              second
#define ll          long long
#define pb              push_back
#define mkp           make_pair
#define pll             pair<ll,ll>
#define vll             vector<int>
#define mll             map<ll,ll>
#define pqg             priority_queue<ll>
#define pqs             priority_queue<ll,vll,greater<ll>>
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod          1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define MAXN   10000001
void online_judge()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
}

void ISO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
int main() {

    ISO();
    online_judge();
    int t;
    t = 1;
    while (t--)
    {

        int n;
        cin >> n;
        int dp[n][3];
        int a, b, c;
        cin >> a >> b >> c;
        dp[0][0] = a;
        dp[0][1] = b;
        dp[0][2] = c;
        for (int i = 1; i < n; ++i)
        {
            cin >> a >> b >> c;
            dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + a;
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + b;
            dp[i][2] = max(dp[i - 1][1], dp[i - 1][0]) + c;
        }
       

        cout << max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]))<< "\n";
    }

    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
    return 0;
}