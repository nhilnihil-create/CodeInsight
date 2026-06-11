#include<ctime>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define file(x)freopen(x".in","r",stdin);freopen(x".out","w",stdout)
#define rt register int
#define l putchar('\n')
#define ll long long
#define r read()
using namespace std;
inline ll read(){
    ll x=0;char zf=1;char ch=getchar();
    while(ch!='-'&&!isdigit(ch))ch=getchar();
    if(ch=='-')zf=-1,ch=getchar();
    while(isdigit(ch))x=x*10+ch-'0',ch=getchar();return x*zf;
}
void write(ll y){if(y<0)putchar('-'),y=-y;if(y>9)write(y/10);putchar(y%10+48);}
void writeln(const ll y){write(y);putchar('\n');}
int k,m,n,x,y,z,cnt,ans;
int F[400010],N[400010],a[400010],num[200010][2];
void add(int x,int y){
	a[++k]=y;
	N[k]=F[x];
	F[x]=k;
}
char c[200010];
int q[200010],h,t;bool vis[200010];
int main(){
	n=r;m=r;scanf("%s",c+1);
	for(rt i=1;i<=m;i++){
		x=r;y=r;
		add(x,y);add(y,x);
		num[y][c[x]=='A']++;
		num[x][c[y]=='A']++;
	}
	
	for(rt i=1;i<=n;i++)if(!num[i][0]||!num[i][1])q[++t]=i,vis[i]=1;
	while(h<t){
		x=q[++h];
		for(rt i=F[x];i;i=N[i])if(!vis[a[i]]){
			if(!--num[a[i]][c[x]=='A'])vis[a[i]]=1,q[++t]=a[i];
		}
	}
	for(rt i=1;i<=n;i++)if(!vis[i])return puts("Yes"),0;
	puts("No");
	return 0;
}
