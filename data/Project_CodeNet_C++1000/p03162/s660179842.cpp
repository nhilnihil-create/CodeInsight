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
#define FOR(i, a, b) for (long long int i = a; i < b; i++)
#define FORI(i, a, b) for (int i = a; i >= b; i--)

typedef vector<int> VI;
typedef vector<ll> VL;
typedef pair<int, int> PI;
typedef pair<ll, ll> PL;
typedef vector<PI> VPI;

int main()
{
    HAPPY_CODING;

    int n;
    cin >> n;

    int a[n][3], dp[n][3];

    FOR(i, 0, n)
    FOR(j, 0, 3)
    cin >> a[i][j];

    dp[0][0] = a[0][0];
    dp[0][1] = a[0][1];
    dp[0][2] = a[0][2];

    FOR(i, 1, n)
    FOR(j, 0, 3)
    {
        if (j == 0)
            dp[i][j] = a[i][j] + max(dp[i - 1][1], dp[i - 1][2]);

        else if (j == 1)
            dp[i][j] = a[i][j] + max(dp[i - 1][0], dp[i - 1][2]);

        else
            dp[i][j] = a[i][j] + max(dp[i - 1][0], dp[i - 1][1]);
    }

    cout << max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2])) << "\n";

    return 0;
}
