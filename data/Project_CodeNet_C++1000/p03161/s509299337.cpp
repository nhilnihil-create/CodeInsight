/*
                    author         : TAPAN SAVANI 
                    codeforces     : savanitapan2001
                    codechef       : savanitapan17
*/

/*
------------------------------------------------------------------------

░██╗░░░░░░░██╗░█████╗░██████╗░██╗░░██╗  ██╗░░██╗░█████╗░██████╗░██████╗░
░██║░░██╗░░██║██╔══██╗██╔══██╗██║░██╔╝  ██║░░██║██╔══██╗██╔══██╗██╔══██╗
░╚██╗████╗██╔╝██║░░██║██████╔╝█████═╝░  ███████║███████║██████╔╝██║░░██║
░░████╔═████║░██║░░██║██╔══██╗██╔═██╗░  ██╔══██║██╔══██║██╔══██╗██║░░██║
░░╚██╔╝░╚██╔╝░╚█████╔╝██║░░██║██║░╚██╗  ██║░░██║██║░░██║██║░░██║██████╔╝
░░░╚═╝░░░╚═╝░░░╚════╝░╚═╝░░╚═╝╚═╝░░╚═╝  ╚═╝░░╚═╝╚═╝░░╚═╝╚═╝░░╚═╝╚═════╝░
 
------------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

#define HAPPY_CODING              \
    ios_base::sync_with_stdio(0); \
    cin.tie(NULL);                \
    cout.tie(NULL);
#define pb push_back
#define mp make_pair
#define Debug(x) cout << #x " = " << (x) << endl
#define SORT(a) sort(a.begin(), a.end())
#define SORTR(a) sort(a.rbegin(), a.rend())
#define mod 1000000007
#define pi 3.141592653589793238
#define ll long long int
#define ull unsigned long long
#define be begin()
#define en end()
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FORI(i, a, b) for (int i = a; i >= b; i--)

typedef vector<int> VI;
typedef vector<ll> VL;
typedef pair<int, int> PI;
typedef pair<ll, ll> PL;
typedef vector<PI> VPI;

int main()
{
    HAPPY_CODING;

    int n, k;
    cin >> n >> k;

    int a[n];
    FOR(i, 0, n)
    cin >> a[i];

    int dp[n];
    dp[0] = 0;
    FOR(i, 1, n)
    {
        int x = min(i, k);
        int y = i - x;
        dp[i] = INT_MAX;

        // while (x--)
        for (int j = i - 1; j >= y; j--)
        {
            dp[i] = min(dp[i], dp[j] + abs(a[i] - a[j]));
        }
    }

    cout << dp[n - 1] << "\n";

    return 0;
}
