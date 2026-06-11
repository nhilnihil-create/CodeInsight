#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define inf 0x3f3f3f3f
#define MN 10005
using namespace std;
inline int in(){
    int x=0;bool f=0;char c;
    for (;(c=getchar())<'0'||c>'9';f=c=='-');
    for (x=c-'0';(c=getchar())>='0'&&c<='9';x=(x<<3)+(x<<1)+c-'0');
    return f?-x:x;
}
struct st{
	int v,id;
}c[MN];
priority_queue<int,vector<int>,greater<int> >q;
int a[MN],t[MN];
int n,k,Q,mn;
int main()
{
	n=in();k=in();Q=in();mn=inf;
	for (int i=1;i<=n;++i) a[i]=in();
	for (int i=1;i<=n;++i){
		while (!q.empty()) q.pop();
		for (int hd=1,tl=0;hd<=n;hd=tl){
			for (;a[hd]<a[i]&&hd<=n;++hd);
			for (tl=hd;a[tl]>=a[i]&&tl<=n;++tl);
			if (tl-hd<k) continue;
			for (int j=hd;j<tl;++j) t[j-hd]=a[j];sort(t,t+tl-hd);
			for (int j=0;j<=tl-hd-k;++j) q.push(t[j]);
		}
		for (int j=1;j<Q;++j)
		if (q.empty()) continue;else q.pop();
		if (q.empty()) continue;
		int u=q.top();q.pop();mn=min(mn,u-a[i]);
	}printf("%d",mn);return 0;
}