#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define myPair pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define qmax priority_queue<int>
#define qmin priority_queue<int,vector<int>,greater<int>>
#define all(x) x.begin(),x.end()
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define FORR(i,a,b) for(int i = a; i >= b; i--)

const int mxn = 310;
double dp[mxn][mxn][mxn];
bool c[mxn][mxn][mxn];
int n;
int a[mxn];

double f(int one, int two, int three)
{
	if(c[one][two][three])
		return dp[one][two][three];
	if(!one && !two && !three)
		dp[one][two][three] = 0;
	else
	{
		dp[one][two][three] = (double)n;
		if(one)
			dp[one][two][three] += (double)one * f(one - 1, two, three);
		if(two)
			dp[one][two][three] += (double)two * f(one + 1, two - 1, three);
		if(three)
			dp[one][two][three] += (double)three * f(one, two + 1, three - 1);
		dp[one][two][three] /= (double)(one + two + three);
	}
	c[one][two][three] = 1;
	return dp[one][two][three];
}

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	int one = 0, two = 0, three = 0;
	FOR(i,1,n)
	{
		cin >> a[i];
		if(a[i] == 1)
			one++;
		else if(a[i] == 2)
			two++;
		else if(a[i] == 3)
			three++;
	}
	memset(c,0,sizeof(c));
	cout << fixed << setprecision(12) << f(one,two,three);

	return 0;
}