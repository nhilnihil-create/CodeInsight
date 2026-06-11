#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define For(i,n) for(int i=0;i<n;i++)
#define mem(a,b) memset(a,b,sizeof(a))
#define int long long int
#define ld long double
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define vpi vector<pair<int,int> >
#define vv vector<int>
#define MAXN 3005
int dp[MAXN][MAXN];
int n;
// void fun(int I , int id)
// {
//     if(id==0)return 1;
// 	if(dp[I][id]!=)
//     int t;
// 	if (str[id] == '>')
// 	{
// 		t = sum(n, id - 1) - sum(I-1,id-1);
// 	}
// 	else{
//        t=sum(I-1,id-1);
// 	}
// 	return t;
// }





int32_t main()
{

	fio;

	cin >> n;
	string str;
	cin >> str;
	int nn = 0;
	// for(int i=1;i<=n;i++)
	// 	nn+=fun(i,n-1)
	// nn=fun(i,n-1);
	// cout<<nn;

	if (str[0] == '>')
	{
		dp[0][1] = 1;
		dp[0][2] = 1;
	}
	else {
		dp[0][2] = 1;

	}

	for (int i = 1; i < n - 1; i++)
	{
		for (int j = 1; j <= i + 2; j++)
		{
			if (str[i] == '<')
			{
				dp[i][j] = (dp[i][j - 1] + dp[i - 1][j - 1]) % mod;
			}
			else {

				dp[i][j] = (dp[i][j - 1] + (dp[i - 1][i + 1] - dp[i - 1][j - 1]) + mod) % mod;
			}
		}
	}
	cout << dp[n - 2][n];

}
