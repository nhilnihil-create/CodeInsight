// ######      ###      #######    #######    ##     #     #####        ###     ##### //
// #     #    #   #          #        #       # #    #    #     #      #   #     ###  //
// #     #   #     #        #         #       #  #   #   #       #    #     #    ###  //
// ######   #########      #          #       #   #  #   #           #########    #   //
// #     #  #       #     #           #       #    # #   #    ####   #       #    #   //
// #     #  #       #    #            #       #     ##   #    #  #   #       #        //
// ######   #       #   #######    #######    #      #    #####  #   #       #    #   //


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> ppl;
#define ain(a,n) for(ll i=0;i<(n);++i)	cin>>(a)[i];
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define loop(i,n) for(ll i=0;i<(n);++i)
#define FOR(i,a,b) for(ll i=(a);i<=(b);++i)
#define FORD(i,a,b) for(ll i=(a);i>=(b);--i)
#define cases ll T=0;cin>>T;while(T--)
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define END "\n"
#define pb push_back
#define mp make_pair
#define go(c,itr) for(auto itr=(c).begin(); itr!=(c).end(); ++itr)
// #define back(c,itr) for(auto itr=(c).rbegin(); itr!=(c).rend(); ++itr)
#define PI 3.14159265359
#define inf 9e18
#define MOD 1000000007
#define MODU 998244353
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 200005
#define BLOCK 555
const string alpha = "abcdefghijklmnopqrstuvwxyz";
const ll N = 200005;
const long double epsilon = 1e-9;
ll binexp(ll a, ll b, ll m) {
	a %= m;
	ll res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return res;
}
ll modinvfermat(ll a, ll m)
{
	return binexp(a, m - 2, m);
}
void task(bool flag)
{
	if (flag)
		cout << "YES\n";
	else
		cout << "NO\n";
}
ll lcm(ll a, ll b)
{
	return ((1LL * a * b) / (__gcd(a, b)));
}

signed main() {

	fast
	ll n, k;
	cin >> n >> k;
	vl a(n + 1);
	FOR(i, 1, n)	cin >> a[i];
	vvl dp(n + 1, vl(k + 1, 0));
	FOR(i, 1, n)	dp[i][0] = 1;
	FOR(j, 1, a[1])	dp[1][j] = 1;
	vl pref(k + 1, 0);
	FOR(i, 2, n)
	{
		pref = vl(k + 1, 0);
		pref[0] = dp[i - 1][0];
		FOR(j, 1, k)
		{
			pref[j] = (pref[j - 1] + dp[i - 1][j]) % MOD;
		}
		FOR(j, 0, k)
		{
			if (j > a[i])
			{
				dp[i][j] = (pref[j] + MOD - pref[j - a[i] - 1]) % MOD;
			}
			else
			{
				dp[i][j] = (pref[j]) % MOD;
			}
		}
	}
	// FOR(i, 1, n)
	// {
	// 	FOR(j, 1, k)
	// 	{
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << END;
	// }
	cout << dp[n][k] << END;




	return 0;
}
