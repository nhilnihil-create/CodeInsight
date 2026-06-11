#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const double EPS = 1e-9;
const int MAX_N = 306;
int N;
int a[MAX_N];
double dp[MAX_N][MAX_N][MAX_N];

double go(int x, int y, int z)
{
	if(!x && !y && !z) return 0;
	double& res = dp[x][y][z];
	if(res > 0) return res;
	const double p1 = 1.0*x/N, p2 = 1.0*y/N, p3 = 1.0*z/N, p4 = 1.0*(N-x-y-z)/N;
	double tmp = 1.0;
	if(x) {
	    tmp += p1*go(x-1, y, z);
	}
	if(y){
	    tmp += p2*go(x+1,y-1,z);
	}
	if(z){
	    tmp += p3*go(x,y+1,z-1);
	}
	res =tmp/(1.0-p4);
	return res;
}

void solve()
{
    int x=0,y=0,z=0;
    for(int i=1;i<=N;++i){
        if(a[i]==1)x++;
        else if(a[i]==2)y++;
        else z++;
    }
	memset(dp,-1,sizeof(dp));
	double ans = go(x,y,z);
	printf("%.12lf\n", ans);
}

int main()
{
	cin >> N;
	for(int i=1;i<=N;++i) cin >> a[i];
	solve();
	return 0;
}