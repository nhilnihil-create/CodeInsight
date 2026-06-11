#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define int             long long
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
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1


#ifndef ONLINE_JUDGE
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); \
						 stringstream _ss(_s); \
						 istream_iterator<string> _it(_ss); \
						 err(_it, args); }
#else
#define error(args...)		42
#endif


void err(istream_iterator<string> it) { cerr << endl;}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << "; ";
	err(++it, args...);
}


void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("debug.txt", "w", stderr);
#endif
}

int ceil2(int a, int b){
    int c = a / b;
    if (c * b < a) c++;
    return c;
}


int32_t main()
{
	c_p_c();

	int n,k; cin>>n>>k;

	int a[n+1];

	for (int i = 1; i < n+1; ++i)
	{
		cin>>a[i];
	}
	int dp[n+1][k+1];

	for (int i = 0; i < k+1; ++i)
	{
		dp[0][i] = 0;
	}

	for (int i = 0; i < n+1; ++i)
	{
		dp[i][0] = 1;
	}

	int psum[k+1];

	for (int i = 1; i < n+1; ++i)
	{
		psum[0] = dp[i-1][0]%mod;
		for (int j = 1; j < k+1; ++j)
		{
			psum[j] = (psum[j-1]%mod + dp[i-1][j]%mod)%mod;
		}

		for (int j = 1; j < k+1; ++j)
		{
			dp[i][j] = 0;

			dp[i][j] = psum[j] - (j-min(a[i], j) - 1 >= 0 ? psum[j-min(a[i], j)-1] : 0);

			dp[i][j] += mod;

			dp[i][j] %= mod;
		}

	}

	cout << dp[n][k];
	
	return 0;
}