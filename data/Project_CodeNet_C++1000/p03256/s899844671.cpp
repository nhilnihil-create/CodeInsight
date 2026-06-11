#include<bits/stdc++.h>
using namespace std;
#define rep(i,s,t) for(int i=(s);i<(t);++i)
#define per(i,s,t) for(int i=((t)-1);i>=s;--i)
#define repb(i,s,t) for(int i=(s);i<=(t);++i)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)x.size())
#define mst(a,b) memset(a,b,sizeof(a))
#define mcpy(des,sor) memcpy(des,sor,sizeof(sor))
#define dd(x) cout<<#x<<'='<<x<<' '
#define de(x) cout<<#x<<'='<<x<<'\n'
#define fi first
#define se second
#define sq(x) ((x)*(x))
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;

const int inf = 0x3f3f3f3f;
const ll mod = 1e9+7;
const db eps = 1e-8;

char io[1<<15],*is=io,*ie=io+1;
#define rd if(++is==ie)ie=(is=io)+fread(io,1,sizeof(io),stdin)
template<class T>
inline bool Cin(T &a){
	a=0;bool s=0;
	if(is==ie)return 0;
	do{rd;if(*is=='-')s=1;}while(!isdigit(*is)&&is!=ie);
	if(is==ie)return 0;
	do{(a*=10)+=*is&15;rd;}while(isdigit(*is)&&is!=ie);
	if(s)a=-a;;return 1;}

inline int Gets(char a[]){
	int p=0;
	if(is==ie)return 0;
	do rd; while(!isgraph(*is)&&is!=ie);
	if(is==ie)return 0;
	do {a[p++]=*is;rd;}while(isgraph(*is)&&is!=ie);
	a[p]=0;return p;}

#define maxn 200005
char s[maxn];
set<int> N[maxn],G[maxn];
queue<int> q;

int main()
{
	int n,m,a,b;
	Cin(n);Cin(m);
	Gets(s+1);
	rep(i,0,m)
	{
		Cin(a),Cin(b);
		if(s[a]==s[b])
			N[a].insert(b),N[b].insert(a);
		else 
			G[a].insert(b),G[b].insert(a);
	}
	repb(i,1,n)if(!sz(N[i])||!sz(G[i]))q.push(i);
	while(!q.empty())
	{
		a=q.front();q.pop();
		for(auto b:N[a])
		{
			N[b].erase(a);
			if(!sz(N[b]))q.push(b);
		}
		for(auto b:G[a])
		{
			G[b].erase(a);
			if(!sz(G[b]))q.push(b);
		}
	}
	repb(i,1,n)if(sz(G[i])&&sz(N[i]))return !printf("Yes\n");
	printf("No\n");
}