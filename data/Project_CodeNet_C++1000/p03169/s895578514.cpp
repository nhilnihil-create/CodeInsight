#include <bits/stdc++.h>
using namespace std;
int st[4] ;
double n;
double dp[305][305][305];
double solve(int a , int b , int c){
	if(a+b+c==0)return 0.0;
	if(dp[a][b][c] >=-0.5)
		return dp[a][b][c];

	double ret =n / (a + b + c);
	if(a){
		ret += solve(a-1 , b , c) *a / (a + b + c);
	}if(b){
		ret += solve(a + 1 , b - 1 , c)  * b/(a + b + c);
	}if(c){
		ret += solve(a , b + 1 , c - 1 )  * c/(a + b +c);
	}
	return dp[a][b][c] = ret;
}
int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int xx ;
	cin>>xx;
	n =xx;
	for(int i = 0; i< xx; i++){
		int x ;
		cin>>x;
		st[x]++;
	}
	for(int i = 0;i <= n ; i++)
		for(int j = 0; j <= n ; j++)
			for(int k = 0; k <= n ; k++)
				dp[i][j][k] = -1;
	cout<<fixed<<setprecision(12)<<solve(st[1] , st[2] , st[3]);
	return 0;
}
