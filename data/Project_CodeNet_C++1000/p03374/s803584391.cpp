#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<=(b);++i)
#define DEC(i,a,b) for(int i=(a);i>=(b);--i)
#define dbg(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
template<typename T,typename U> inline bool smax(T&x,const U&y){return y>x?(x=y,1):0;}
template<typename T,typename U> inline bool smin(T&x,const U&y){return y<x?(x=y,1):0;}
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define X first
#define Y second
template<typename T>
inline void rd(T&w){
	char c;
	while(!isdigit(c=getchar()));w=c&15;
	while(isdigit(c=getchar()))w=(w<<1)+(w<<3)+(c^48);
}
const int N=1e5+7;
int n,v[N],top;
ll x[N],c,s[N],t[2][N<<1][25];
inline ll ask(int l,int r,int k){
	if(l>r)return 0;
	int s=log2(r-l+1);
	return max(t[k][l][s],t[k][r-(1<<s)+1][s]);
}
int main(){
	rd(n),rd(c);top=log2(n)+1;
	REP(i,1,n)rd(x[i]),rd(v[i]),s[i]=v[i]+s[i-1],t[0][i][0]=s[i]-x[i],t[1][i][0]=s[i]-2ll*x[i];
	REP(j,1,top)REP(i,1,n)
		t[0][i][j]=max(t[0][i][j-1],t[0][i+(1<<j-1)][j-1]),
		t[1][i][j]=max(t[1][i][j-1],t[1][i+(1<<j-1)][j-1]);
	
	ll ans=ask(1,n,0);
	DEC(i,n,1){
		int p=upper_bound(x+1,x+i,c-x[i])-x-1;
		smax(ans,max(s[n]-s[i-1]-c+x[i]+ask(1,p,1),2ll*(x[i]-c)+s[n]-s[i-1]+ask(p+1,i-1,0)));
		smax(ans,x[i]-c+s[n]-s[i-1]);
	}
	cout<<max(ans,0ll);
	return 0;
}
