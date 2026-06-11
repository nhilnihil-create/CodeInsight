#include<bits/stdc++.h>
using namespace std;
const int N=2e5+11;
vector<int> g[N];
char s[N];
int n,m,d[N][2];
int vi[N];
int main(){
#ifdef flukehn
	freopen("g.in","r",stdin);
#endif
	int i,x,y;
	cin>>n>>m;
	scanf("%s",s+1);
	for(i=1;i<=n;++i)s[i]-='A';
	for(i=1;i<=m;++i){
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
		++d[x][s[y]];
		++d[y][s[x]];
	}
	queue<int> q;
	for(i=1;i<=n;++i)
		if(!d[i][0]||!d[i][1])vi[i]=1,q.push(i);
	while(!q.empty()){
		x=q.front();
	//	cerr<<x<<endl;
		q.pop();
		for(int y:g[x]){
			if(!(--d[y][s[x]])&&!vi[y])vi[y]=1,q.push(y);
		}
	}
	for(i=1;i<=n;++i)
		if(!vi[i]){
			puts("Yes");
			return 0;
		}
	puts("No");
}