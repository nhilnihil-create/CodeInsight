#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define ld long double
#define mod 998244353LL
#define eps 1e-13
// #define PI 3.141592653589793238L
#define INF 1000000011
#define INFLL 100000000000011LL
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pil pair<int, long long>
#define pli pair<long long, int>
#define mp make_pair
#define F first
#define S second
#define pb push_back
#define fo(i,a,n) for(i = (a); i < (n); i++)
#define gtl(x) getline(cin, (x))
#define flsh fflush(stdout)
#define sws ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define gcd __gcd
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)((a).size())
#define io_file freopen("D:/Coding Problems/Contest/input_file.in", "r", stdin); freopen("D:/Coding Problems/Contest/output_file.out", "w", stdout)

ll modx(ll Base, ll exponent)
{
	ll ans = 1;
	if(Base == 1)
		return Base;
	while(exponent)
	{
		if(exponent & 1)
			ans = (ans * Base)%mod;
		Base = (Base * Base)%mod;
		exponent = exponent >> 1;
	}
	return ans;
}

ll inmodx(ll num)
{
	return (modx(num, mod-2LL));
}

bool cmp(pii a, pii b)//true for a before b
{
	if(a.S < b.S)
		return 1;
	if(a.S > b.S)
		return 0;
	if(a.F <= b.F)
		return 1;
	return 0;
}

const int N = (2e3) + 9;
const int M = (2e6) + 9;
const int LOGN = ((int)log2(N)) + 3;
const int LOGM = ((int)log2(M)) + 3;
const int BUCK = 900;

int a[N];
bitset < M > dp;

void solve()
{
	int n, i, ans = 0, sum = 0, val;
	cin >> n;
	fo(i,1,n+1)
	{
		cin >> a[i];
		sum += a[i];
	}
	val = sum/2;
	dp[0] = 1;
	fo(i,1,n+1)
		dp |= (dp<<a[i]);
	ans = 0;
	fo(i,1,val+1)
		if(dp[i])
			ans = i;
	cout << (sum-ans) << '\n';
	return;
}

int main()
{
	sws;
	clock_t clk;
	clk = clock();
	//io_file;
	// srand(clock());

	//Code here
	int t = 1, cs;
	cout << fixed << setprecision(3);
	// cin >> t;
	fo(cs,1,t+1)
	{
		// cout << "Case " << cs << ": ";
		solve();
	}
	// Code ends here

	clk = clock() - clk;
	cerr << fixed << setprecision(6) << "Time: " << ((double)clk)/CLOCKS_PER_SEC << "\n";
	return 0;
}