#include <bits/stdc++.h>
using namespace std;

/*	Author: 🆉🅴🅽🅾🅻🆄🆂	*/

int n, a[4] = {0};
double dp[301][301][301];
bool vis[301][301][301] = {0};
double calc(int c1, int c2, int c3){
	if(c1 < 0 || c2 < 0 || c3 < 0)	return 0;
	if(c1+c2+c3 == 0)	return 0;
	if(vis[c1][c2][c3])	return dp[c1][c2][c3];
	vis[c1][c2][c3] = 1;
	double ans = c1*(1+calc(c1-1, c2, c3)) + c2*(1+calc(c1+1, c2-1, c3)) + c3*(1+calc(c1, c2+1, c3-1)) + (n-c1-c2-c3);
	ans /= (c1 + c2 + c3);
	return dp[c1][c2][c3] = ans;
}
int main(){
	cin>>n;	int x;
	for(int i = 0; i < n; i++){ cin>>x; a[x]++; }
	cout<<fixed<<setprecision(50)<<calc(a[1], a[2], a[3]);
}

// Time: O(C1*C2*C3)	Ci => Count of plates with i sushi
// Space: O(C1*C2*C3)