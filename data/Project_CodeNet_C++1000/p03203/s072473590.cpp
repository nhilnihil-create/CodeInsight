#include<ctime>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<unordered_map>
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
unordered_map<int,int>b[200010];
int Min[200010];
int main(){
	n=r;m=r;int q=r;
	for(rt i=1;i<=n;i++)Min[i]=m+1;
	for(rt i=1;i<=q;i++){
		x=r;y=r;Min[x]=min(Min[x],y);
		b[x][y]=1;
	}
	for(rt x=2,y=1;x<=n;x++){
		if(!b[x][y+1]&&y<m)y++;
		if(y>=Min[x]){
			write(x-1);
			return 0;
		}
	}
	write(n);
	return 0;
}
