#include <bits/stdc++.h>
using namespace std;
const int N=200005;
struct Gragh{
	static const int M=N*2;
	int cnt,y[M],nxt[M],fst[N];
	void add(int a,int b){
		y[++cnt]=b,nxt[cnt]=fst[a],fst[a]=cnt;
	}
}g;
int n,m,c[N],out[N][2],del[N];
char s[N];
int q[N],head,tail;
int main(){
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for (int i=1;i<=n;i++)
		if (s[i]=='A')
			c[i]=0;
		else
			c[i]=1;
	memset(out,0,sizeof out);
	for (int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		out[a][c[b]]++;
		out[b][c[a]]++;
		g.add(a,b);
		g.add(b,a);
	}
	memset(del,0,sizeof del);
	head=tail=0;
	for (int i=1;i<=n;i++)
		if (!out[i][0]||!out[i][1])
			q[++tail]=i,del[i]=1;
	while (head<tail){
		int x=q[++head];
		for (int i=g.fst[x];i;i=g.nxt[i]){
			int y=g.y[i];
			if (del[y])
				continue;
			out[y][c[x]]--;
			if (!out[y][c[x]])
				q[++tail]=y,del[y]=1;
		}
	}
	puts(tail!=n?"Yes":"No");
	return 0;
}