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

// int dp[21][2097152+1];

int32_t main()
{
	c_p_c();

	int n; cin>>n;

	bool a[n][n];

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin>>a[i][j];
		}
	}


	int sz = 1LL<<n;

	vector<vector<int>> dp(n, vector<int>(sz));
	// error(sz);

	// error(1LL<<22);


	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < (sz); ++j)
		{
			// error(i,j);
			dp[i][j] = 0;

			int mask=1LL<<(n-1);

			if(__builtin_popcountll(j) == i+1)
			{
				for (int k = 0; k < n; ++k)
				{
					if(a[i][k] == 1 && (j&(mask>>k)))
					{
						if(i-1 >= 0)
							dp[i][j] += dp[i-1][(j^(mask>>k))];
						else
							dp[i][j] = 1;

						dp[i][j] %= mod;
					}
				}
			}
		}
	}

	// for (int i = 0; i < n; ++i)
	// {
	// 	for (int j = 0; j < 1<<(n); ++j)
	// 	{
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }
	
	cout << dp[n-1][(sz)-1];

	return 0;
}