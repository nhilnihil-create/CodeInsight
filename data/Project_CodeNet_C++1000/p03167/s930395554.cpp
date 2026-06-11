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

#define HAPPY_CODING                                                           \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(NULL);                                                               \
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

int main() {
  HAPPY_CODING;

  long long int h, w;
  cin >> h >> w;

  char s[h][w];
  FOR(i,0,h){
	FOR(j,0,w)
    	cin >> s[i][j];
  }

  long long int dp[h][w], i=0;
  memset(dp, 0, sizeof(dp));

  while(s[0][i]!='#' && i<w)
  {
    	dp[0][i] = 1;
    	i++;
  }

  i=0;
  while(s[i][0] != '#' && i<h)
  {
	  	dp[i][0] = 1;
    	i++;
  }

  FOR(i,1,h)
  {
	  FOR(j,1,w)
	  {
			if(s[i][j] != '#')
			{
				if(s[i-1][j] == '#')
				{
					dp[i][j] = dp[i][j-1];
				}
				else if(s[i][j-1] == '#')
				{
					dp[i][j] = dp[i-1][j];
				}
				else 
				{
					dp[i][j] = (dp[i-1][j] + dp[i][j-1])%mod;
				}
			}
			// cout << dp[i][j] << " ";
	  }
	//   cout << "\n";
  }

	cout << (dp[h-1][w-1])%mod << "\n";

  return 0;
}
