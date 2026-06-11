#include<bits/stdc++.h>
using namespace std;
#define ll  long long int
const int  M = 1e9 + 7;
int n;
double dp[301][301][301];

double f(int x, int y, int z)
{
	if(x < 0 || y < 0 || z < 0)
		return 0;
	if(x == 0 && y == 0 && z == 0)
		return 0;
	if(dp[x][y][z] > 0)
		return dp[x][y][z];
	double p0 = (n - (x+y+z))/(1.0 *n);
	double p1 = x/(1.0 *n);
	double p2 = y/(1.0 *n);
	double p3 = z/(1.0*n);

	//return (1 + p1 * f(x-1, y, z) + p2*f(x+1, y-1, z) + p3*f(x, y+1, z-1))/(1.0*(1.0-p0));
	return dp[x][y][z] = (n + x*f(x-1, y, z) + y*f(x+1, y-1, z) + z*f(x, y+1, z-1))/(x+y+z);
}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int i, j, wt, m;
	
	cin >> n;
	int ones = 0, twos = 0, threes = 0;
	for(i = 0; i < n; i++)
	{
		cin >> m;
		if(m == 1) ones++;
		else if(m == 2) twos++;
		else threes++;
	}
	cout << setprecision(10) << f(ones, twos, threes);
}
