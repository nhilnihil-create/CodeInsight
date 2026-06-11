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

void FIO()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int n;
vector<double> a;
vector<vector<double>>dp(3000 + 1, vector<double>(3000 + 1, -1));

double solve(int i, int heads)
{
	//base case

	if (i > n) //if coins are over and no of heads>k return 1 else return 0
	{
		if (heads >= (n + 1) / 2)
			return 1.0;
		else
			return 0.0;
	}

	if (dp[i][heads] != -1)
		return dp[i][heads];

	//first coin can have two choice head or tail if head increase cnt of head otherwise dont increase
	//multiply their probabilities also

	return 	dp[i][heads] = a[i] * solve(i + 1, heads + 1) + (1.0 - a[i]) * solve(i + 1, heads);
}

int32_t main()
{
	FIO();
	cin >> n;

	a.resize(n + 1);

	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	int k = (n + 1) / 2; //i need k heads

	double ans = solve(1, 0); //index of first coin and no of heads

	cout << ps(ans, 10) << '\n';

	return 0;
}