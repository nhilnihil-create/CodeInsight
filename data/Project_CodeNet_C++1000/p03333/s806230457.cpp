#include<bits/stdc++.h>
#define up(l,r,i) for(int i=l;i<=r;i++)
#define dn(l,r,i) for(int i=l;i>=r;i--)
using namespace std;

typedef long long LL;
const int INF =2147483647;
int qread(){
	int w=1,c,ret;
	while((c=getchar())> '9'||c< '0')
	w=(c=='-'?-1:1); ret=c-'0';
	while((c=getchar())>='0'&&c<='9')
	ret=ret*10+c-'0';
	return ret*w;
}
const int MAXN =1e5+3;
struct Node{
	int l,r,ID;
	Node(int _l,int _r,int _ID){
		l=_l,r=_r,ID=_ID;
	}
	Node(){}
}P[MAXN];
bool vis[MAXN];
struct cmp1{
	bool operator ()(Node a,Node b){
		return a.l<b.l;
	}
};
struct cmp2{
	bool operator ()(Node a,Node b){
		return a.r>b.r;
	}
};
priority_queue <Node,vector<Node>,cmp1> pq1;
priority_queue <Node,vector<Node>,cmp2> pq2;
int n,L[MAXN],R[MAXN];
LL calc(bool type){
	LL ret=0,pos=0,_pos;
	memset(vis,0,sizeof(vis));
	up(1,n,i) pq1.push(Node(L[i],R[i],i)),
			  pq2.push(Node(L[i],R[i],i));
	up(1,n,i){
		Node t=(type?pq1.top():pq2.top());
		type?pq1.pop():pq2.pop();
		if(vis[t.ID]) continue; else vis[t.ID]=true;
		if(pos<t.l) _pos=t.l; else
		if(pos>t.r) _pos=t.r; else _pos=pos;
		ret+=(LL)abs(pos-_pos),type=!type,pos=_pos;
	}
	return (ret+=(LL)abs(pos));
}
int main(){
	n=qread();
	up(1,n,i) L[i]=qread(),R[i]=qread();
	printf("%lld\n",max(calc(true),calc(false)));
	return 0;
}
/*
2
2147483647 2147483647
-2147483647 -2147483647
*/