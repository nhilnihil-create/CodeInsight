#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
std::vector<int>G[200010];
int d[200010][2],del[200010],fa[200010];
char s[200010];
std::queue<int>que;
int hd(int x){return fa[x]==x?x:fa[x]=hd(fa[x]);}
void Union(int x,int y){
	x=hd(x),y=hd(y);
	if(x==y)puts("Yes"),exit(0);
	fa[x]=y;
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),m=gi(),a,b;
	scanf("%s",s+1);
	while(m--)a=gi(),b=gi(),G[a].push_back(b),G[b].push_back(a),++d[a][s[b]-'A'],++d[b][s[a]-'A'];
	for(int i=1;i<=n;++i)if(!d[i][0]||!d[i][1])del[i]=1,que.push(i);
	while(!que.empty()){
		int x=que.front();que.pop();
		for(int i:G[x])if(!--d[i][s[x]-'A']&&!del[i])del[i]=1,que.push(i);
	}
	for(int i=1;i<=n;++i)if(!del[i])fa[i]=i;
	for(int i=1;i<=n;++i)if(!del[i])for(int j:G[i])if(!del[j]&&j>=i)Union(i,j);
	puts("No");
	return 0;
}

