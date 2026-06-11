#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define PB push_back
#define MP make_pair
#define PII pair<int,int>
#define FIR first
#define SEC second
#define ll long long
using namespace std;
template <class T>
inline void rd(T &x) {
	x=0; char c=getchar(); int f=1;
	while(!isdigit(c)) { if(c=='-') f=-1; c=getchar(); }
	while(isdigit(c)) x=x*10-'0'+c,c=getchar(); x*=f;
}
const ll inf=1e18;
const int N=5010;
ll dp[N][2*N],pre[N][2*N];
int per[N],p[N],n;
int A,B;

int main() {
	rd(n),rd(A),rd(B);
	for(int i=1;i<=n;++i) rd(per[i]),p[per[i]]=i;
	memset(dp,0x3f,sizeof(dp));
	dp[0][1]=0;
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=2*n+1;++j) pre[i-1][j]=min(j>1 ? pre[i-1][j-1] : inf,dp[i-1][j]);
		for(int j=1;j<=2*n+1;++j)
			dp[i][j]=pre[i-1][j&1 ? j : j-1]+(j<p[i]*2)*B+(j>p[i]*2)*A;
	}
	ll res=inf;
	for(int j=1;j<=2*n+1;++j)
		res=min(res,dp[n][j]);
	printf("%lld",res);
	return 0;
}