#include<bits/stdc++.h>
using namespace std;
#define ff              first
#define ss              second
#define int             long long int
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define vv(type)		vector<vector<type>>
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define db(x) 			cout<<x<<" "
#define db1(x) 			cout<<x<<'\n'
#define db2(x,y) 		cout<<x<<" "<<y<<'\n'
#define db3(x,y,z) 		cout<<x<<" "<<y<<" "<<z<<'\n'
#define rep(i,n) 		for(int i=0;i<(n);++i)
#define repA(i,a,n) 	for(int i=a;i<=(n);++i)
#define repD(i,a,n) 	for(int i=a;i>=(n);--i)
#define so(a) 			sort(a.begin(),a.end())
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
// to find all local maximaa and minima in O(n)
//	 for (int i=1;i<=n;i++)
//        {
//            if (i==1 || i==n || (p[i-1]<p[i])!=(p[i]<p[i+1]))
//           ans.push_back(p[i]);
//        }
int dx[] = { -1, 1, -1, 0, 0, -1, 1, 1 };
int dy[] = { -1, -1, 1, -1, 1, 0, 0, 1 };
int gcd(int a, int b)
{
	if (!b)
		return a;
	return gcd(b, a % b);
}
int modular_expo(int x, int y, int m)
{
	int ans = 1;
	while (y)
	{
		if (y & 1)
			ans = (ans % m * x % m) % m;
		x = (x % m * x % m) % m;
		y /= 2;
	}
	return ans % m ;
}
int power(int x, int y)
{
	int ans = 1;
	while (y)
	{
		if (y & 1)
			ans = (ans * x);
		x *= x;
		y /= 2;
	}
	return ans;
}

void solve()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m, x, y;
	cin >> n >> m;
	std::vector<std::vector<int>> a(n, vector<int>(m)), dp(n, vector<int>(m));
	char ch;
	rep(i, n)
	{
		rep(j, m)
		{
			cin >> ch;
			if (ch == '.')
				a[i][j] = 1;
			else
				a[i][j] = 0;
		}
	}
	rep(i, m)
	if (a[0][i])
		dp[0][i] = 1;
	else break;
	rep(i, n)
	if (a[i][0])
		dp[i][0] = 1;
	else break;
	repA(i, 1, n - 1)
	repA(j, 1, m - 1)
	{
		if (a[i][j])
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
		else
			dp[i][j] = 0;
	}
	db(dp[n - 1][m - 1] % mod);
}

int32_t main()
{
	solve();
	return 0;
}
