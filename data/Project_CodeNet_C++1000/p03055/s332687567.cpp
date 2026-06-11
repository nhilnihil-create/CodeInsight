#include <bits/stdc++.h>

const int N=int(2e5)+10;
int n,dim,d[N],sg[N];
std::vector<int> e[N];
void dfs(int x,int fa) {
	int a=1,b=0;
	for (auto p:e[x]) if (p!=fa) {
		dfs(p,x);
		if (a<d[p]+1) {
			b=a;
			a=d[p]+1;
		} else if (b<d[p]+1) b=d[p]+1;
	}
	dim=std::max(dim,std::max(a+b-1,a));
	d[x]=a;
}
int main() {
	scanf("%d",&n);
	for (int i=1;i<n;++i) {
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].emplace_back(y);
		e[y].emplace_back(x);
	}
	dfs(1,0);
	sg[1]=1;
	sg[2]=0;
	for (int i=3;i<=n;++i) {
		if (sg[i-1]==0||sg[i-2]==0) sg[i]=1;
		else sg[i]=0;
	}
	puts(sg[dim]?"First":"Second");
}