#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#include <bits/stdc++.h>
using namespace std;
template<class t> inline t read(t &x){
	char c=getchar();bool f=0;x=0;
	while(!isdigit(c)) f|=c=='-',c=getchar();
	while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
	if(f) x=-x;return x;
}
template<class t,class ...A> inline void read(t &x,A &...a){
	read(x);read(a...);
}
template<class t> inline void write(t x){
	if(x<0) putchar('-'),write(-x);
	else{if(x>9) write(x/10);putchar('0'+x%10);}
}

const int N=1e4+5;
int f[N],son[N],n,val[N],ans[N],m,tot;
queue<int> q;
vector<int> g[N];

void dfs(int x,int fa){
	f[x]=fa;
	son[x]=g[x].size()-(fa>0);
	for(int y:g[x]) if(y^fa) dfs(y,x);
}

signed main(){
	read(n);
	for(int i=1,x,y;i<n;i++){
		read(x,y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for(int i=1;i<=n;i++) read(val[i]),tot+=val[i];
	sort(val+1,val+1+n);
	dfs(1,0);
	for(int i=1;i<=n;i++) if(!son[i]) q.push(i);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		ans[x]=val[++m];
		if(!--son[f[x]]) q.push(f[x]);
	}
	write(tot-val[n]);puts("");
	for(int i=1;i<=n;i++) write(ans[i]),putchar(' ');
}