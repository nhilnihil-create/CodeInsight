#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<queue>
#define MN 40002
#define MM 5000001
#define ll long long
#define ld long double
#define inf 0x7fffffff
#define clz 1000000007
#define ers(arr,val) memset(arr,val,sizeof(arr));
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repd(i,b,a) for(int i=(b);i>=(a);i--)
#define repe(i,u) for(int i=h[u];i;i=e[i].nx)
using namespace std;
int n,sum=0,N,p=0;
int ans[3001][3001];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=5000;i++){
		sum+=i;
		if(sum==n) {N=i;break;}
		if(sum>n) break;
	}
	if(N){
		rep(i,1,N)rep(j,i,N) ans[i][j]=++p;
		p=0;
		rep(j,1,N)rep(i,j,N) ans[i+1][j]=++p;
		puts("Yes");
		printf("%d\n",N+1);
		rep(i,1,N+1){
			printf("%d ",N); rep(j,1,N) printf("%d ",ans[i][j]);puts("");
		}
	}
	else puts("No");
	return 0;
}
