#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<deque>
#include<stack>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<stdlib.h>
#include<cassert>
#include<time.h>
#include<bitset>
using namespace std;
const long long mod=998244353;
const long long inf=mod*mod;
const long long d2=(mod+1)/2;
const double EPS=1e-13;
const double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
double ABS(double a){return max(a,-a);}
char in[310];
int dp[310][310][310];

int solve(int a,int b,int c){
	if(~dp[a][b][c])return dp[a][b][c];
	if(a>b)return 0;
	if(a==b)return 1;

	int ret=0;
	if(in[a]==in[b]){
		ret=max(ret,solve(a+1,b-1,c)+2);
	}
	ret=max(ret,solve(a+1,b,c));
	ret=max(ret,solve(a,b-1,c));
	if(c){
		ret=max(ret,solve(a+1,b-1,c-1)+2);
	}
	return dp[a][b][c]=ret;
}
int main(){
	scanf("%s",in);
	int a;scanf("%d",&a);
	int n=strlen(in);
	for(int i=0;i<310;i++)for(int j=0;j<310;j++)for(int k=0;k<310;k++)dp[i][j][k]=-1;
	printf("%d\n",solve(0,n-1,a));
}