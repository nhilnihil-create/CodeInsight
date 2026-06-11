#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

#define int int64_t
#define ld long double

const int MOD = 1e9+7;
const int N = 3e2+5;

ld dp[N][N][N];
int n;

ld solve(int c1, int c2, int c3) {
	if(dp[c1][c2][c3]>=0)
		return dp[c1][c2][c3];
	// cout<<c1<<" "<<c2<<" "<<c3<<endl;
	int c0 = n-c1-c2-c3;
	ld cv = 0;
	ld p1 = c1*1.0/n;
	ld p2 = c2*1.0/n;
	ld p3 = c3*1.0/n;
	ld p0 = c0*1.0/n;
	if(c1>0)
		cv += p1*(solve(c1-1, c2, c3)+1);
	if(c2>0)
		cv += p2*(solve(c1+1, c2-1, c3)+1);
	if(c3>0)
		cv += p3*(solve(c1, c2+1, c3-1)+1);
	cv += p0;
	dp[c1][c2][c3]=cv/(1-p0);
	return dp[c1][c2][c3];
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	memset(dp, -1, sizeof(dp));
	dp[0][0][0]=0;
	cin>>n;
	int x;
	int c1=0, c2=0, c3=0;
	for(int i=0;i<n;i++) {
		cin>>x;
		if(x==1)
			c1++;
		if(x==2)
			c2++;
		if(x==3)
			c3++;
	}

	cout<<setprecision(15)<<solve(c1,c2,c3);

	return 0;
}