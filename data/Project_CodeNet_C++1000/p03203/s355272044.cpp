#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
int n,m,k;
set<int>Map[666666];
int main() {
	read(n);read(m);read(k);int res=n;
	while(k--){
		int x,y;read(x);read(y);Map[x].insert(y);
	}
	for(int i=2,l=1,r=1;i<=n;i++){
		set<int>::iterator it=Map[i].lower_bound(l);
		if(it!=Map[i].end()&&(*it)<=r){printf("%d\n",i-1);return 0;}
		if(r+1<=m&&!Map[i].count(r+1))r++;
	}
	cout<<n;
	return 0;
}
