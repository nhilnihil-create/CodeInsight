#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

#define LL long long
#define fgx cerr<<"--------------"<<endl;
#define dgx cerr<<"=============="<<endl;

inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}
const int MAXN = 400010;
const int INF = 2147483600;

int N,M;
int Node[MAXN<<1],Next[MAXN<<1],Root[MAXN+1],cnt;
int deg[MAXN+1]; queue<int> que;
char str[MAXN+1];

inline void insert(int u,int v){
	Node[++cnt]=v; Next[cnt]=Root[u]; Root[u]=cnt; deg[v]++;
}

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	N=read(),M=read();
	scanf("%s",str+1);
	for(int i=1;i<=M;i++){
		int u=read(),v=read(); 
		int x=(str[u]!=str[v]);
		insert(u+(x^1)*N,v+x*N);
		insert(v+(x^1)*N,u+x*N);
	}  queue<int> que; int all=0;
	for(int i=1;i<=2*N;i++) if(!deg[i]) que.push(i);
	while(!que.empty()){
		int k=que.front(); ++all; que.pop();
		for(int x=Root[k];x;x=Next[x]){
			int v=Node[x]; --deg[v];
			if(!deg[v]) que.push(v);
		}
	} if(all==N*2) puts("No");
	else puts("Yes");
	return 0;
}


