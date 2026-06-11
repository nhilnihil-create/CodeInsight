#include <bits/stdc++.h>
#define fo(i,a,b) for(i=a;i<=b;i++)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;
typedef long long ll;
inline int read(){
	int n=0,f=1;char c;
	for(c=getchar();c!='-'&&(c<'0'||c>'9');c=getchar());
	if (c=='-') f=-1,c=getchar();
	for(;c>='0'&&c<='9';c=getchar()) n=(n<<3)+(n<<1)+(c&15);
	return n*f;
}
const int N=2e5+5;
int H,W,n,i,j,x,y,ans,now;
vector<int>g[N];
map<int,int>p[N];
int main(){
	H=read(),W=read(),n=read();
	fo(i,1,n){
		x=read(),y=read();
		g[y].push_back(x);
		p[y][x]=1;
	}
	ans=H,now=1;
	fo(i,1,W) {
		sort(g[i].begin(),g[i].end());
		int cnt=g[i].size();
		for(j=0;j<cnt&&g[i][j]<=now;j++);
		if (j!=cnt) ans=min(ans,g[i][j]-1);
	 	if (i==W) break;
	 	for(now++;p[i+1][now];now++);
	 	if (now>=H) break;
	}printf("%d\n",ans);
}