#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#include<cstdlib>
#define LL long long
#define LD long double
using namespace std;
const int NN=5000 +117;
const int MM= +117;
int read(){
	int fl=1,x;char c;
	for(c=getchar();(c<'0'||c>'9')&&c!='-';c=getchar());
	if(c=='-'){fl=-1;c=getchar();}
	for(x=0;c>='0'&&c<='9';c=getchar())
		x=(x<<3)+(x<<1)+c-'0';
	return x*fl;
}
void open(){
	freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
}
void close(){
	fclose(stdin);
	fclose(stdout);
}


int m,n;
LL dp[NN][NN]={};
int p[NN]={};
int a,b;
int main(){
	//open();
	n=read();
	a=read(),b=read();
	for(int i=1;i<=n;++i)p[i]=read();
	
	memset(dp,60,sizeof dp);
	dp[0][0]=0;
	for(int i=1;i<=n;++i){
		for(int j=0;j<=n;++j){
			if(j<p[i]){
				dp[i][p[i]]=min(dp[i][p[i]],dp[i-1][j]);
				dp[i][j]=min(dp[i][j],dp[i-1][j]+a);
			}
			else{
				dp[i][j]=min(dp[i][j],dp[i-1][j]+b);
			}
		}
	}
	LL ans=1e18;
	for(int j=0;j<=n;++j){
		ans=min(dp[n][j],ans);
	}
	printf("%lld\n",ans);
	close();
	return 0;
}