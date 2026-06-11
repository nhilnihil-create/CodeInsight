#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 303
using namespace std;

int N;								//number of dishes 
//int a[4];							//number of dishes with i pieces of sushi in it
bool vis[MAXN][MAXN][MAXN];			//visited
long double dp[MAXN][MAXN][MAXN];		//expected number of steps to finish dp[i][j][k]

long double solve(int n1,int n2,int n3){
	
	if(vis[n1][n2][n3])
		return dp[n1][n2][n3];
	
	vis[n1][n2][n3]=true;
	
	if(n1==0&&n2==0&&n3==0)
		return dp[n1][n2][n3]=0;

	long double occ = (long double)n1+n2+n3;
	long double exp = (N-occ)/occ;
	
	if(n1>0)	exp += n1*(1+solve(n1-1,n2,n3))/occ;
	if(n2>0)	exp += n2*(1+solve(n1+1,n2-1,n3))/occ;
	if(n3>0) 	exp += n3*(1+solve(n1,n2+1,n3-1))/occ;

	return dp[n1][n2][n3] = exp;

}

int main(){
 	int a[]={0,0,0,0};
	cin>>N;
	int currPiece;
	for(int i=0;i<N;i++){
		cin>>currPiece;
		a[currPiece]++;
	}
	printf("%.10llf",solve(a[1],a[2],a[3]));
}
