#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
#define PI pair<int,int>
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
const int N=200005;
int n,m,vis[N],tong[N][2];
vector<int> v[N];
char ch[N];
bool check(int x){
	return tong[x][0]&&tong[x][1];
}
void dfs(int p){
	if(vis[p])return;
	vis[p]=1;
	for(auto i:v[p])if(--tong[i][ch[p]]==0)dfs(i);
}
signed main(){
	n=read(); m=read();
	scanf("%s",ch+1);
	for(int i=1;i<=n;i++)ch[i]-='A';
	for(int i=1;i<=m;i++){
		int s=read(),t=read();
		v[s].push_back(t); v[t].push_back(s);
	}
	for(int i=1;i<=n;i++)for(auto j:v[i])tong[i][ch[j]]++;
	for(int i=1;i<=n;i++)if(!check(i))dfs(i);
	for(int i=1;i<=n;i++)if(check(i)){
		puts("Yes"); return 0;
	}
	puts("No");
}