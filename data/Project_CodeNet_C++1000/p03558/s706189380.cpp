#include<bits/stdc++.h>
#define LL long long 
using namespace std;

inline int read(){
	int res=0,f=1;char ch=' ';
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)){res=res*10+ch-'0';ch=getchar();}
	return res*f;
}
const int N=1e5+5;
const int mod=998244353;
int n,S,T;
int d[N],flag[N];
int head[N*20],to[N*20],w[N*20],nxt[N*20],cnt;
inline void qxx(int x,int y,int z){
	cnt++;nxt[cnt]=head[x];head[x]=cnt;to[cnt]=y;w[cnt]=z;
}
inline void SPFA(){
	memset(d,63,sizeof(d));
	queue<int>q;q.push(S);d[S]=0;flag[S]=1;
	while(!q.empty()){
		int k=q.front();q.pop();flag[k]=0;
		for(register int i=head[k];i;i=nxt[i]){
			int kk=to[i];
			if(d[kk]>d[k]+w[i]){
				d[kk]=d[k]+w[i];
				if(!flag[kk]){
					flag[kk]=1;q.push(kk);
				}
			}
		}
	}
}
int main(){
	n=read();
	S=0;T=1;
	for(register int i=1;i<=n;i++)
		for(register int j=0;j<=9;j++)
			qxx(i,((i-1)*10+j)%n+1,j);
	for(register int i=1;i<=9;i++) qxx(0,i+1,i);
	SPFA();
	printf("%d\n",d[1]);
	return 0;
}