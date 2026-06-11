#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define mod 1000000007LL
#define eps 1e-13
// #define PI 3.141592653589793238L
#define INF 2000000011LL
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

bool cmp(pll a, pll b)//true for a before b
{
	if(a.F*b.S < b.F*a.S)
		return 1;
	if(a.F*b.S > b.F*a.S)
		return 0;
	if(a.F <= b.F)
		return 1;
	return 0;
}

const int N = (1e5) + 9;
const int M = (N<<2) + 9;
const int LOGN = ((int)log2(N)) + 3;
const int LOGM = ((int)log2(M)) + 3;
const int BUCK = 100;
const int SQRT = BUCK+9;

pii a[N];
set < pii > stl, str;//stl -> leftmost r, str -> rightmost l
int n;

ll func(int bit)
{
	int i, pt = 0, z;
	ll ans = 0;
	stl.clear();
	str.clear();
	fo(i,1,n+1)
	{
		stl.insert({a[i].S,i});
		str.insert({-a[i].F,i});
	}
	fo(i,1,n+1)
	{
		if((i&1) == bit)
			z = str.begin()->S;
		else
			z = stl.begin()->S;
		str.erase({-a[z].F,z});
		stl.erase({a[z].S,z});
		if(pt < a[z].F)
		{
			ans += abs(pt-a[z].F);
			pt = a[z].F;
		}
		else if(pt > a[z].S)
		{
			ans += abs(pt-a[z].S);
			pt = a[z].S;
		}
	}
	ans += abs(pt);
	return ans;
}

void solve()
{
	int i;
	ll ans = 0;
	cin >> n;
	fo(i,1,n+1)
		cin >> a[i].F >> a[i].S;
	ans = max(func(0), func(1));
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