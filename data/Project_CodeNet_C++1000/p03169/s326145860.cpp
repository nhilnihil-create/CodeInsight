#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int n=0;
int st[4]={};
double dp[305][305][305]={};
 
double solve(int a, int b, int c){
	if(a+b+c == 0) return 0.0;
	
	if(dp[a][b][c] != -1)
		return dp[a][b][c];
		
	// probability of select dish having sushi
	double ks = (double)n/(a+b+c);
	double ans=0;
	if(a) {
			   // require draw dice * prob of select a, (a=no of dish having a sushi) 
		ans += ( solve(a-1, b, c) + ks ) * a/(a+b+c);
	}
	
	if(b) {
			   // require draw dice * prob of select a, (a=no of dish having a sushi) 
			   // a+1 remove 2's sushi do become 1
		ans += ( solve(a+1, b-1, c) + ks ) * b/(a+b+c);
	}
	
	if(c) {
			   // require draw dice * prob of select a, (a=no of dish having a sushi) 
		ans += ( solve(a, b+1, c-1) + ks ) * c/(a+b+c);
	}
	
	return dp[a][b][c] = ans;
}
 
void solve(){
	cin >> n;
	int x;
	for(int i=0; i<n; i++) {
		cin >> x;
		st[x]++;
	}
	
	for(int i=0; i<=n; i++)
		for(int j=0; j<=n; j++)
			for(int k=0; k<=n; k++)
				dp[i][j][k]=-1;
	
	double ans = solve(st[1], st[2], st[3]);	
	cout << setprecision(12) << fixed << ans << "\n";
}
 
int main(){
	solve();
}
