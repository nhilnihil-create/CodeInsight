#include<bits/stdc++.h>
using namespace std;
void solve(){
	double n,m,x,y,p,q;
	cin>>n;
	//expectancy =1/probabiluty;
	vector<int>A(4);
	for(int i=0;i<n;i++){
		cin>>x;
		A[x]++;
	}
	int a,b,c;
	a=A[1]+A[2]+A[3];
	b=A[2]+A[3];
	c=A[3];
	double dp[a+1][b+1][c+1];
	dp[0][0][0]=0;
	//dp[i][j][k] means probability when i 1-sushi dish, j 2-sushi dish, k 3- sushi dish
	double t=0;
	for(int k=0;k<=c;k++){
		for(int j=0;j<=(b-k);j++){
			for(int i=0;i<=(a-j-k);i++){
				t=j+k+i; //total ways to eat
				if((i+j+k)>0) dp[i][j][k]=n/double(t);
				if(k>0) dp[i][j][k]+=(double(k)/t)*dp[i][j+1][k-1];
				if(j>0) dp[i][j][k]+=(double(j)/t)*dp[i+1][j-1][k];
				if(i>0) dp[i][j][k]+=(double(i)/t)*dp[i-1][j][k];
			}
		}
	}
	cout<<setprecision(15)<<dp[A[1]][A[2]][A[3]]<<"\n";

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();

}