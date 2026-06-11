#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int arr[301];
double dp[301][301][301];

int n;
double solve(int x, int y, int z) {

	//cout<<"#x "<<x<<" #y "<<y<<" #z "<<z<<endl;
	if(x<0 || y<0 || z<0)
		return 0;
	if (x == 0 && y == 0 && z == 0)
		return 0;

	if (dp[x][y][z] > -0.9)
		return dp[x][y][z];

	dp[x][y][z] = ((n + x * solve(x - 1, y, z) + y * solve(x+1, y-1 , z) + z * solve(x, y+1 , z - 1)));
	//Finally x=0 y=0 z=0
	dp[x][y][z]/=(x+y+z);

	return dp[x][y][z];
}



int main() {

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	int x=0, y=0, z=0;




	for (int i = 0; i < n; i++)
	{	cin >> arr[i];
		if (arr[i] == 1)
			x++;
		else if (arr[i] == 2)
			y++;
		else if (arr[i] == 3)
			z++;
	}


	memset(dp,-1.0,sizeof(dp));
	//cout<<x<<" "<<y<<" "<<z<<endl;
	cout<<fixed<<setprecision(10)<<solve(x,y,z)<<endl;



}