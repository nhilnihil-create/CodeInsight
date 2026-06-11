#include <bits/stdc++.h> 

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
 
#define nl '\n'
 
#define y1 aza_ibagaliev
 
#define f first
#define s second
	
#define ed end()
#define bg begin()
#define rbg rbegin()
 
#define rv reverse
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define ppf pop_front
 
#define sz size()
#define all(x) x.bg, x.ed
 
#define pll pair < ll, ll >
#define pii pair < int, int >
 
#define sqr(x) ((x) * 1ll * (x))
#define sqrd(x) ((x) * 1.0 * (x))
 
#define speed ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
 
#define rnl cout << "----------------------------------------" << nl
 
#define bit __builtin_popcount
 
inline ll bip(ll x, ll n, ll mod){ll res=1;while(n){if(n & 1){res=(res*x)%mod;}x=(x*x)%mod;n>>=1;}return res;}
        	
const int ppr = 257;
const ll INF = 2e18;
const int inf = 2e9;
const int mod = 1e9 + 7;
const int N = 1e5 + 123;
const ld pi = 3.1741592653589793238462643;
 
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int n, dp[3333][3333], p[3333];
string s;

main() {             	
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);

//	srand(time(NULL));

	cin >> n >> s;
	s = "##" + s;

	dp[1][1] = 1;
	for(int i = 1; i <= n; i++)
		p[i] = 1;
	for(int i = 2; i <= n; i++) {
		for(int j = 1; j <= i; j++) {
			if(s[i] == '<') {
				dp[i][j] = p[j - 1];
			} else {
				dp[i][j] = (p[i - 1] - p[j - 1] + mod) % mod;
			}
		}
		for(int j = 1; j <= i; j++)
			p[j] = (p[j - 1] + dp[i][j]) % mod;
	}                               

	cout << p[n];
    return 0;                                           	
}