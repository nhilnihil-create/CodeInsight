#include <bits/stdc++.h>
#define rg register
#define LL long long 

using namespace std;

const int M=500010;
const int N=1000010;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int cnt,head[M],nxt[N<<1],to[N<<1],w[N<<1];
void add(int x,int y,int z){
	to[++cnt]=y;
	w[cnt]=z;
	nxt[cnt]=head[x];
	head[x]=cnt;
}
int d[M];bool vis[M];
void spfa(){
	queue<int>q;
	memset(d,63,sizeof(d));
//	memset(vis,false,sizeof(vis));
	d[1]=0;q.push(1);vis[1]=true;
	while(!q.empty()){
		int k=q.front();q.pop();vis[k]=false;
		for(int i=head[k];i;i=nxt[i]){
			int kk=to[i];
			if(d[kk]-d[k]>w[i]){
				d[kk]=d[k]+w[i];
				if(!vis[kk]){
					vis[kk]=true;
					q.push(kk);
				}
			}
		}
	}
}
int main()
{
//	freopen("magic.in","r",stdin);
//	freopen("magic.out","w",stdout);
	int k=read();
	if(k==1){puts("1");return 0;}
	for(rg int i=0;i<k;i++){
		add(i,(i+1)%k,1);
		add(i,(i*10)%k,0);
	}
	spfa();
	printf("%d\n",d[0]+1);
	return 0;
}