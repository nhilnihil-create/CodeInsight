#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX
#define mod 1000000007
#define int long long

double dp[301][301][301];

double sushi(vector<int> &a, int x, int y, int z){
	if(x == 0 && y == 0 && z == 0)return dp[x][y][z] = 0;
	if(x < 0 || y < 0 || z < 0)return 0;
	if(dp[x][y][z] > -0.9)return dp[x][y][z];
	
	int n = a.size();
	return dp[x][y][z] = (n + (x*sushi(a,x-1,y,z) + y*sushi(a,x+1,y-1,z) + z*sushi(a,x,y+1,z-1)))/(x+y+z);
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	int i;
	for (i = 0; i < n; i++)cin >> a[i];
	int j,k;

	for(i=0;i<=n;i++){
		for(j=0;j<=n;j++){
			for(k=0;k<=n;k++)dp[i][j][k] = -1;
		}
	}

	int x = 0,y = 0,z = 0;

	for(i=0;i<n;i++){
		if(a[i] == 1)x += 1;
		else if(a[i] == 2)y += 1;
		else if(a[i] == 3)z += 1;
	}
	
	double cnt = sushi(a,x,y,z);

	cout<<setprecision(15)<<cnt<<endl;

	return;
}

int32_t main() {
	std::ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	solve();
	return 0;
}
