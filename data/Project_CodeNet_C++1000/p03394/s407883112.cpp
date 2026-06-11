#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define mod 1000000007LL
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

const int N = (3e4) + 9;
const int M = (N<<2) + 9;
const int LOGN = ((int)log2(N)) + 3;
const int LOGM = ((int)log2(M)) + 3;
const int BUCK = 2*550;
const int SQRT = BUCK+9;

const int MAX = 30000;

bool mark[N];
vi arr, primes = {2,3};

void solve()
{
	int n, i, cnt = 0, bal;
	cin >> n;
	if(n == 3)
	{
		cout << "2 5 63\n";
		return;
	}
	if(n <= 15000)
	{
		if(n % 3 == 0)
		{
			fo(i,1,n-4+1)
				mark[i*2] = 1;
			mark[3] = mark[9] = mark[15] = mark[21] = 1;
		}
		else
		{
			fo(i,1,n-2+1)
				mark[i*2] = 1;
			mark[3] = mark[9] = 1;
		}
	}
	else if(n % 2 == 0)
	{
		for(i = 2; i <= MAX; i+=2)
			mark[i] = 1;
		cnt = MAX/2;
		for(i = 3; i <= MAX; i+=3)
			if(!mark[i])
			{
				mark[i] = 1;
				cnt++;
				if(cnt == n)
					break;
			}
	}
	else
	{
		for(i = 2; i < MAX; i+=2)
			mark[i] = 1;
		cnt = MAX/2 - 1;
		for(i = 3; i <= MAX; i+=3)
			if(!mark[i])
			{
				mark[i] = 1;
				cnt++;
				if(cnt == n)
					break;
			}
	}
	
	fo(i,2,MAX+1)
		if(mark[i])
			cout << i << " ";
	cout << '\n';
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