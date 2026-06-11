#include <bits/stdc++.h>
#define MAXN 310
using namespace std;
int n,sushi[4],a,cnt;
double dp[MAXN][MAXN][MAXN];

int main(){
	cin>>n;
	for(int i=0;i<n;cin>>a,++sushi[a],++i);
	for(int i=0;i<=sushi[3];++i){
		for(int j=0;j<=sushi[3]+sushi[2];++j){
			for(int k=0;k<=sushi[3]+sushi[2]+sushi[1];++k){
				if(i+j+k==0) continue;
				cnt=i+j+k;
				if(i) dp[i][j][k]+=dp[i-1][j+1][k]*i/cnt;
				if(j) dp[i][j][k]+=dp[i][j-1][k+1]*j/cnt;
				if(k) dp[i][j][k]+=dp[i][j][k-1]*k/cnt;
				dp[i][j][k]+=1.0*n/cnt;
			}
		}
	}
	cout<<fixed<<setprecision(15)<<dp[sushi[3]][sushi[2]][sushi[1]]<<endl;
	return 0;
}