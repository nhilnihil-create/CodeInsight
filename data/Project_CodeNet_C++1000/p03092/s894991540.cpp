#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define REP(NAME, NUM) for (size_t NAME = 0; NAME < (NUM); ++NAME)
#define BREP(NAME, NUM) for (size_t NAME = (NUM)-1; NAME >= 0; --NAME)
#define ALL(NAME) (NAME).begin(), (NAME).end()
#define VEC(TYPE, A, NAME, INIT) vector<TYPE> NAME(A, INIT)
#define VEC2(TYPE, A, B, NAME, INIT) vector<vector<TYPE>> NAME(A, vector<TYPE>(B, (INIT)))

int main()
{
	ll n, a, b;
	cin >> n>>a>>b;
	VEC(ll,n,p,0);
	VEC(ll,n,q,0);
	REP(i,n)
	{
		cin>>p[i];
		q[p[i]-1] = i;
	}
	VEC2(ll,n+1,n,dp,0);

	REP(i,n) REP(j,n)
	{
		ll cost = 0;
		if( q[i] < j ) cost = a;
		else if( q[i] > j ) cost = b;
		dp[i+1][j] = j == 0
			? dp[i][j] + cost
			: min( dp[i+1][j-1], dp[i][j] + cost );
	}

	cout << dp[n][n-1] << endl;

	return 0;
}