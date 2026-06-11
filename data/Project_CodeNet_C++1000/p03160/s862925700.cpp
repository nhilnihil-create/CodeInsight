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

int main()
{
    // Fast Input/Output
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // Test Cases
    int t = 1;
//    cin >> t;

    while (t--) {
        lli n; sc(n);
        vlli h(n);
        fo(i, n)
        {
            sc(h[i]);
        }
        vlli dp(n);
        dp[0] = 0;
        dp[1] = abs(h[1]-h[0]);
        for(int i=2; i<n; i++)
        {
            dp[i] = min(dp[i-2]+abs(h[i]-h[i-2]), dp[i-1]+abs(h[i]-h[i-1]));
        }
        pr(dp[n-1]);
    }
    return 0;
}





