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

string LCS(string x, string y, int n, int m)
{
    int dp[n+1][m+1];

    FOR(i,0,n+1)
    {
        FOR(j,0,m+1)
        {
            if(i==0 || j==0)
                dp[i][j] = 0;

            else if(x[i-1] == y[j-1])
                dp[i][j] = dp[i-1][j-1]+1;

            else 
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    int index = dp[n][m];
    char ans[index+1];
    ans[index] = '\0';

    int i = n,j=m;
    while(i>0 && j>0)
    {
        if (x[i-1] == y[j-1]) 
	{ 
		ans[index-1] = x[i-1];
		i--; j--; index--;
	} 

	else if (dp[i-1][j] > dp[i][j-1]) 
		i--; 
	else
		j--; 
    }

    return ans;
}

int main()
{
    HAPPY_CODING;

    string x,y;
    cin >> x >> y;

    string ans = LCS(x, y, x.length(),y.length());
    cout << ans << "\n";

    return 0;
}
/*

abcdef
adbcde
5

*/