#include <bits/stdc++.h>
using namespace std;
  
#define fo(i, n) for (long long i = 0; i < n; i++)
#define sc(x) cin >> x
#define pr(x) cout << x << endl;
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define br cout << endl
typedef long long int lli;
typedef pair<int, int> pii;
typedef pair<lli, lli> pll;
typedef vector<int> vi;
typedef vector<lli> vlli;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
lli max(lli a, lli b){ return (a>b)?a:b; }
lli min(lli a, lli b){ return (a<b)?a:b; }

lli gcd(lli a, lli b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}


lli n;
int a[100005], b[100005], c[100005];

int main()
{
    // Fast Input/Output
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // Test Cases
    int t = 1;
//    cin >> t;

    while (t--) {
        sc(n);
        int dp[n+1][3];
        dp[0][0] = dp[0][1] = dp[0][2] = 0;
        for(int i=1; i<=n; i++)
        {
            cin >> a[i] >> b[i] >> c[i];
            dp[i][0] = dp[i][1] = dp[i][2] = 0;
        }
        
        for(int i=1; i<=n; i++)
        {
            dp[i][0] = max(dp[i-1][1]+a[i], dp[i-1][2]+a[i]);
            dp[i][1] = max(dp[i-1][0]+b[i], dp[i-1][2]+b[i]);
            dp[i][2] = max(dp[i-1][0]+c[i], dp[i-1][1]+c[i]);
        }
        
        pr(max({dp[n][0], dp[n][1], dp[n][2]}));
    }
    return 0;
}





