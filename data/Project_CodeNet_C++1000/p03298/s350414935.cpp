#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
const LL N=19;
const LL p1=10007;
LL n; char s[N*2];
map <LL,LL> M[19];
inline LL pw(LL x,LL y){
	LL ans=1;
	while(y){
		if(y&1)ans*=x;
		x=x*x; y>>=1;
	}
	return ans;
}
inline void dfs1(LL pos,LL kR,LL kB,LL cntR){
	if(pos==n+1){
		M[cntR][kB*pw(p1,cntR)-kR]++;
		return ;
	}
	dfs1(pos+1,kR+s[pos]*pw(p1,cntR),kB,cntR+1);
	dfs1(pos+1,kR,kB*p1+s[pos],cntR);
}
LL ans=0;
inline void dfs2(LL pos,LL kR,LL kB,LL cntR){
	if(pos==2*n+1){
		ans+=M[n-cntR][kR*pw(p1,n-cntR)-kB];
		return ;
	}
	dfs2(pos+1,kR+s[pos]*pw(p1,cntR),kB,cntR+1);
	dfs2(pos+1,kR,kB*p1+s[pos],cntR);
}
int main(){
	scanf("%lld%s",&n,s+1);
	dfs1(1,0,0,0); dfs2(n+1,0,0,0);
	printf("%lld",ans);
	return 0;
}