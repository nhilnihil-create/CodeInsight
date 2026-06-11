/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#include<bits/stdc++.h>
#define ll long long
#define inf 1000000005
#define mod 1000000007
#define put putchar('\n')
#define F(i,a,b) for (int i=(a);i<=(b);i++)
#define D(i,a,b) for (int i=(a);i>=(b);i--)
#define go(i,t) for (int i=head[t];i;i=Next[i])
#define sqr(x) ((x)*(x))
#define re register
#define mp make_pair
#define fi first
#define se second
#define pa pair<int,int>
#define pb push_back
#define be begin()
#define en end()
#define ret return puts("-1"),0;
#define N 500055
//#define int ll
using namespace std;
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read(){char c=getchar();int tot=1;while ((c<'0'|| c>'9')&&c!='-') c=getchar();if (c=='-'){tot=-1;c=getchar();}
int sum=0;while (c>='0'&&c<='9'){sum=sum*10+c-'0';c=getchar();}return sum*tot;}
inline void wr(int x){if (x<0) {putchar('-');wr(-x);return;}if(x>=10)wr(x/10);putchar(x%10+'0');}
inline void wrn(int x){wr(x);put;}inline void wri(int x){wr(x);putchar(' ');}
inline void wrn(int x,int y){wri(x);wrn(y);}inline void wrn(int a,int b,int c){wri(a);wrn(b,c);}
int n,m,x,y,a[N],f[N][2],vis[N];
char str[N];
int nedge,head[N*2],to[N*2],Next[N*2];
#define V to[i]
void add(int a,int b){
   Next[++nedge]=head[a];head[a]=nedge;to[nedge]=b;
}
void dfs(int x){
	vis[x]=0;
	go(i,x){
		f[V][a[x]]--;
		if (f[V][a[x]]==0&&vis[V]) dfs(V);
	}
}
signed main(){
	n=read();m=read();
	scanf("%s",str+1);
	F(i,1,n) a[i]=str[i]-'A',vis[i]=1;
	F(i,1,m){
		x=read();y=read();add(x,y);add(y,x);
		f[x][a[y]]++;f[y][a[x]]++;
	}
	F(i,1,n){
		if (vis[i]&&(f[i][0]==0||f[i][1]==0)) dfs(i);
	} 
	int pd=0;
	F(i,1,n) pd|=vis[i];
	if (pd) puts("Yes");
	else puts("No");
	return 0;
}
