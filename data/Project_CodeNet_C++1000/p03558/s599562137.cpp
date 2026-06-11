//https://www.luogu.org/problem/AT3621
#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000
#define mp make_pair
#define pii pair<int,int>
#define pb push_back
#define ri register int
#define rep(i,a,b) for(ri i=(a);i<=(b);++i)
#define rep2(i,a,b,c) for(ri i=(a);i<=(b);i+=(c))
#define REP(i,a,b) for(ri i=(a);i>=(b);--i)
#define REP2(i,a,b,c) for(ri i=(a);i>=(b);i-=(c))
#define fi first
#define se second
using namespace std;

inline int read(){
	ri x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^'0'),c=getchar();
	return x*f;
}
inline void write(ri x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}

const int N=1e6+5;
int n;
bool vis[N];
deque<pii> q;
int main()
{
	n=read();q.push_front(mp(1,1));
	while(1){
		pii t=q.front();q.pop_front();
		if(vis[t.fi]) continue;
		vis[t.fi]=1;
		if(!t.fi) return write(t.se),0;
		q.push_front(mp(t.fi*10%n,t.se));
		q.push_back(mp((t.fi+1)%n,t.se+1));
	}
	return 0; 
}