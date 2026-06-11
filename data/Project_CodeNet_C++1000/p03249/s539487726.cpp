#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
#define poly vector<ll>
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
#define fi first
#define se second
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){write(a); puts("");}
inline void wri(ll a){write(a); putchar(' ');}
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
const int N=100005;
ll sum,d[N];
map<ll,int> M;
int q[N],sz[N],vis[N],fa[N];
vector<int> v[N];
void GG(){
	puts("-1"); exit(0);
}
bool cmp(int a,int b){
	return d[a]<d[b];
}
void dfs(int p,int dep){
	vis[p]=1; sum+=dep;
	for(auto i:v[p])if(!vis[i])dfs(i,dep+1);
}
int main(){
	int n=read();
	For(i,1,n)M[d[q[i]=i]=read()]=i;
	sort(q+1,q+n+1,cmp);
	Rep(i,n,2){
		sz[q[i]]++;
		auto it=M.find(d[q[i]]-n+2*sz[q[i]]);
		if(it==M.end())GG();
		fa[q[i]]=it->second;
		sz[fa[q[i]]]+=sz[q[i]];
		v[fa[q[i]]].pb(q[i]);
	}
	dfs(q[1],0);
	For(i,1,n)if(!vis[i])GG();
	if(sum!=d[q[1]])GG();
	For(i,2,n){wri(fa[q[i]]); writeln(q[i]);}
}