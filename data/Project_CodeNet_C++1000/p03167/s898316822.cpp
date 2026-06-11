	#include<bits/stdc++.h>

	using namespace std;
	#define PI              3.1415926536

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
	#define mod 1000000007
	#define inf             1e18
	#define ps(x,y)         fixed<<setprecision(y)<<x
	#define mk(arr,n,type)  type *arr=new type[n];
	#define w(x)            int x; cin>>x; while(x--)
	#define REP(i,n) for(i=0;i<n;i++)
	#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
	mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());


	void c_p_c()
	{
	#ifndef  ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	}

	void solve()
	{
		int n, s;

		cin >> n >> s;

	}

	int32_t main()
	{
		//c_p_c();
		FIO;

		int n, m;
		cin >> n >> m;

		char ch[n + 1][m + 1];

		int dp[n + 1][m + 1];

		int i, j;

		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= m; j++)
			{
				cin >> ch[i][j];

			}
		}
		// for (i = 1; i <= n; i++)
		// {
		// 	for (j = 1; j <= m; j++)
		// 	{
		// 		cout << ch[i][j];

		// 	}
		// 	cout << endl;
		// }

		for (i = n; i >= 1; i--)
		{
			for (j = m; j >= 1; j--)
			{
				if (i == n && j == m)
				{
					dp[i][j] = 1;
				}
				else
				{
					int o1 = (i == n) ? 0 : dp[i + 1][j];

					int o2 = (j == m) ? 0 : dp[i][j + 1];

					dp[i][j] = (o1 + o2) % mod;

					if (ch[i][j] == '#')
						dp[i][j] = 0;
				}


			}
		}
		// for (i = 1; i <= n; i++)
		// {
		// 	for (j = 1; j <= m; j++)
		// 	{
		// 		cout << dp[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }
		cout << dp[1][1];


	}