#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
typedef long long ll;
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pii pair < int , int >
#define pll pair < ll, ll >
#define mp make_pair
#define ff first
#define ld long double
#define ss second
#define vi vector < int >
#define vll vector < ll >
#define pb push_back
#define pf push_front
#define PI 3.1415926535897932384626
#define INF 0x3f3f3f3f
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)

const int mod = 1'000'000'007;

int mpow(int base, int exp) {
  base %= mod;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((ll)result * base) % mod;
    base = ((ll)base * base) % mod;
    exp >>= 1;
  }
  return result;
}


	
int main()
{
		fastio;
		ll t = 1;
		//cin >> t;
		rep(tt,1,t+1)
		{
			ll n, K;
			cin >> n >> K;
			vll A(n);
			rep(i, 0, n)
			{
				cin >> A[i];
			}
			vector<ll> dp(K+1);
			rep(i, 0, K+1)
			{
				for(auto y:A)
				{
					if(i-y >=0 && dp[i-y] == 0)
					{
						dp[i] = 1;
					}
				}
			}
			if(dp[K])
			{
				cout << "First" << endl;
			}
			else
			{
				cout << "Second" << endl;
			}
		}
		return 0;
	}
					
