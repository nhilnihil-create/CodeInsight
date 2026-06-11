#include <cstdio>
#include <cstring>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);++i)
#define per(i,a,b) for(register int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;
inline void chkmax(int &x,int y){
	x<y?(x=y):0;
}
inline void chkmin(int &x,int y){
	x>y?(x=y):0;
}
const int N=5005;
int dp[N][N],a[N];
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()){
		if(ch=='-'){
			f=-1;
		}
	}
	for(;ch>='0'&&ch<='9';ch=getchar()){
		x=(x<<1)+(x<<3)+(ch^48);
	}
	return x*f;
}
signed main() {
	int n=read(),A=read(),B=read(),ans=1ll<<60;
	rep(i,1,n){
		a[i]=read();
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++){
			if(a[i]>j){
				chkmin(dp[i][j],dp[i-1][j]+A);
				chkmin(dp[i][a[i]],dp[i-1][j]);
			}
			else{
				chkmin(dp[i][j],dp[i-1][j]+B);
			}
		}
	}
	rep(i,0,n){
		chkmin(ans,dp[n][i]);
	}
	printf("%lld\n",ans);
	return 0;
}
