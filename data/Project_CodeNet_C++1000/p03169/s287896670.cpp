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
#define back(c,itr) for(auto itr=(c).rbegin(); itr!=(c).rend(); ++itr)
#define PI 3.14159265359
#define inf 9e18
#define MOD 1000000007
#define MODU 998244353
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 1000005
const string alpha = "abcdefghijklmnopqrstuvwxyz";
const ll N = 305;
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
vector<vector<vector<double>>> dp(N, vector<vector<double>>(N, vector<double>(N, 0.0)));
vector<vector<vector<ll>>> vis(N, vvl(N, vl(N)));
vl state(4, 0);
ll n;
double solve(ll i, ll j, ll k)
{
	if (i + j + k == 0)
		return 0.0;
	if (vis[i][j][k] == 1)
		return dp[i][j][k];
	vis[i][j][k] = 1;
	double E_x = n * 1.0 / (i + j + k);
	double res = 0.0;
	if (i > 0)
		res += solve(i - 1, j, k) * i / (i + j + k);
	if (j > 0)
		res += solve(i + 1, j - 1, k) * j / (i + j + k);
	if (k > 0)
		res += solve(i, j + 1, k - 1) * k / (i + j + k);
	res += E_x;
	return dp[i][j][k] = res;
}
signed main() {

	fast
	cin >> n;
	loop(i, n)
	{
		ll x;
		cin >> x;
		++state[x];
	}
	double ans = solve(state[1], state[2], state[3]);
	cout << fixed << setprecision(10) << ans << END;




	return 0;
}