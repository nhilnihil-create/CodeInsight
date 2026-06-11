#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mem(x,v) memset(x,v,sizeof(x))
#define Rep(i,a,b) for(register int i=(a);i<=int(b);++i)
#define rep(i,a,b) for(register int i=(a);i<int(b);++i)
#define Dep(i,a,b) for(register int i=(a);i>=int(b);--i)
#define gc getchar
#define pc putchar
#define fi first
#define se second
inline ll read(){
    ll x=0,f=1;char c=gc();
    for(;!isdigit(c);c=gc())if(c=='-')f=-1;
    for(;isdigit(c);c=gc())x=(x<<1)+(x<<3)+(c^48);
    return x*f;
}
inline void write(ll x){if(x<0)x=-x,pc('-');if(x>=10)write(x/10);putchar(x%10+'0');}
inline void writeln(ll x){write(x);pc('\n');}
inline void wri(ll x){write(x);pc(' ');}
const int maxn=5005;
ll dp[maxn][maxn],a[maxn];
ll n,A,B,ans;
int main(){
	n = read(),A = read(),B = read();
	ans = 1ll << 60;
	Rep(i,1,n) a[i] = read();
	memset(dp,0x3f,sizeof(dp));
	dp[0][0] = 0;
	Rep(i,1,n)Rep(j,0,n){
		if(a[i] > j)
			dp[i][j]=min(dp[i][j],dp[i-1][j] + A),
			dp[i][a[i]]=min(dp[i][a[i]],dp[i-1][j]);
		else dp[i][j]=min(dp[i][j],dp[i-1][j]+B);
	}
	Rep(i,0,n) ans=min(ans,dp[n][i]);
	writeln(ans);
	return 0;
}