#include<cstdio>
#include<vector>
#include<algorithm>
#define pb push_back
#define rep(i,l,r) for (int i=(l); i<=(r); i++)
using namespace std;

const int N=200010;
char s[N];
int n,m,x,y,d[N][2],vis[N];
vector<int>v[N],q;

int main(){
	scanf("%d%d%s",&n,&m,s+1);
	for (int i=m; i; i--){
		scanf("%d%d",&x,&y); v[x].pb(y); v[y].pb(x);
		++d[x][s[y]-'A']; ++d[y][s[x]-'A'];
	}
	rep(i,1,n) if (!d[i][0] || !d[i][1]) q.pb(i),vis[i]=1;
	for (int j=0; j<(int)q.size(); j++){
		int sz=v[q[j]].size()-1;
		rep(i,0,sz){
			int p=v[q[j]][i];
			if (!--d[p][s[q[j]]-'A'] && !vis[p]) q.pb(p),vis[p]=1;
		}
	}
	if ((int)q.size()<n) puts("Yes"); else puts("No");
	return 0;
}