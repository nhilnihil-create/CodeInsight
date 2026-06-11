#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define mod 998244353LL
#define eps 1e-13
// #define PI 3.141592653589793238L
#define INF 1000000011
#define INFLL 1000000000000000011LL
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

bool cmp(pair < pii, int > a, pair < pii, int > b)//true for a before b
{
	if(a.F.F/300 < b.F.F/300)
		return 1;
	if(a.F.F/300 > b.F.F/300)
		return 0;
	if(a.F.S < b.F.S)
		return 1;
	if(a.F.S > b.F.S)
		return 0;
	if(a.F <= b.F)
		return 1;
	return 0;
}

const int N = (2e5) + 9;
const int M = (N<<2) + 9;
const int LOGN = ((int)log2(N)) + 3;
const int LOGM = ((int)log2(M)) + 3;
const int BUCK = 2*550;
const int SQRT = BUCK+9;

ll a[N], val[N];
int n;
ll x;

ll func(int c)
{
	int i, z;
	ll ans = 1LL*c*x;
	fo(i,0,c)
	{
		ans += (2LL*a[n-1-i]);
		val[i] = 1;
	}
	for(i = n-1; i >= 0; i--)
	{
		z = i % c;
		ans -= (a[i]*val[z]*val[z]);
		val[z]++;
		ans += (a[i]*val[z]*val[z]);
	}
	return ans;
}

ll tersea(int l, int r)
{
	if(l > r)
		return INFLL;
	int mid1 = l + (r-l)/3;
	int mid2 = l + 2*(r-l)/3;
	ll val1 = func(mid1);
	ll val2 = func(mid2);
	ll vall = func(l);
	ll valr = func(r);
	ll ans = min(vall,min(val1,min(val2,valr)));
	if(val1 <= vall && val2 <= val1)
		return min(ans, tersea(mid1+1,r-1));
	if(val2 <= valr && val1 <= val2)
		return min(ans, tersea(l+1,mid2-1));
	return min(ans, min(tersea(mid1+1,r-1), tersea(l+1,mid2-1)));
}

void solve()
{
	int i;
	ll ans = 0;
	cin >> n >> x;
	fo(i,0,n)
		cin >> a[i];
	ans = tersea(1,n) + 1LL*n*x;
	cout << ans << '\n';
	return;
}

int main()
{
	sws;
	clock_t clk;
	clk = clock();
	// io_file;
	// srand (time(NULL));

	//Code here
	int t = 1, cs;
	cout << fixed << setprecision(9);
	// cin >> t;
	fo(cs,1,t+1)
	{
		// cout << "Case #" << cs << ": ";
		solve();
	}
	// Code ends here

	clk = clock() - clk;
	cerr << fixed << setprecision(6) << "Time: " << ((double)clk)/CLOCKS_PER_SEC << "\n";
	return 0;
}