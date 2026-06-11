#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#define dbg(x) cerr << #x << " = " << x <<endl
#define dbg2(x,y) cerr<< #x <<" = "<< x <<"  "<< #y <<" = "<< y <<endl
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
template<typename T>inline T _min(T A,T B){return A<B?A:B;}
template<typename T>inline T _max(T A,T B){return A>B?A:B;}
template<typename T>inline bool MIN(T&A,T B){return A>B?(A=B,1):0;}
template<typename T>inline bool MAX(T&A,T B){return A<B?(A=B,1):0;}
template<typename T>inline void _swap(T&A,T&B){A^=B^=A^=B;}
template<typename T>inline T read(T&x){
	x=0;int f=0;char c;while(!isdigit(c=getchar()))if(c=='-')f=1;
	while(isdigit(c))x=x*10+(c&15),c=getchar();return f?x=-x:x;
}
const int N=1e5+7;
struct thxorz{int nxt,to,w;}G[N*11];
int Head[N],tot;
int n;
inline void Addedge(int x,int y,int z){G[++tot].to=y,G[tot].nxt=Head[x],Head[x]=tot,G[tot].w=z;}
int dis[N];
priority_queue<pii,vector<pii>,greater<pii> > pq;
#define y G[j].to
inline void dij(){
	memset(dis,0x3f,sizeof dis);for(register int i=1;i<10;++i)MIN(dis[i%n],i),pq.push(make_pair(dis[i%n],i%n));
	while(!pq.empty()){
		int d=pq.top().first,x=pq.top().second;pq.pop();
		if(d^dis[x])continue;//dbg2(x,d);
		if(x==0)return;
		for(register int j=Head[x];j;j=G[j].nxt)if(MIN(dis[y],d+G[j].w))pq.push(make_pair(dis[y],y));
	}
}
#undef y
int main(){//freopen("test.in","r",stdin);//freopen("test.ans","w",stdout);
	read(n);
	for(register int i=1;i<n;++i)for(register int j=0;j<10;++j)Addedge(i,(10*i+j)%n,j);
	dij();
	return printf("%d\n",dis[0]),0;
}