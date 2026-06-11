#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define lg long long
#define db double
#define lb(x) ((x)&-(x))
#define ft first
#define sd second

#define HII cerr<<"HI"<<endl
#define LLLINE cerr<<"@@@@@@@@@@@@@@@@@@@@"<<endl

template <class _T_>
void read(_T_& d){
	d=0;int f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar())if(c=='-')f*=-1;
	for(;c>='0'&&c<='9';c=getchar())d=d*10+c-'0';
	d*=f;
}

/************************************************/
#define MN 5005
int n,a,b;
lg dp[MN][MN];
int v[MN];
#define Mi(x,y) (x)=(x)<(y)?(x):(y)
int main(){
	read(n);read(a);read(b);
	for(int i=1;i<=n;++i)read(v[i]);
	memset(dp,0x3f,sizeof dp);
	dp[0][0]=0;
	for(int i=1;i<=n;++i){
		for(int j=0;j<=n;++j){
			if(j<=v[i]){
				Mi(dp[j][i],dp[j][i-1]+a);
				Mi(dp[v[i]][i],dp[j][i-1]);
			}else{
				Mi(dp[j][i],dp[j][i-1]+b);
			}
		}
	}
	lg res=0x3f3f3f3f3f3f3f3f;
	for(int i=0;i<=n;++i)Mi(res,dp[i][n]);
	cout<<res;
	return 0;
}
