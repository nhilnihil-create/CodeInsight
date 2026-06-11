#include<ctime>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define p 1000000007
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
int a[200010],qz[200010],inv[200010];
int main(){
	n=r;inv[0]=inv[1]=1;
	for(rt i=1;i<=n;i++)a[i]=r;
	for(rt i=2;i<=n;i++)inv[i]=1ll*inv[p%i]*(p-p/i)%p;
	for(rt i=2;i<=n;i++)(inv[i]+=inv[i-1])%=p;
	for(rt i=1;i<=n;i++)(ans+=1ll*a[i]*(inv[i]+inv[n-i+1]-1)%p)%=p;
	for(rt i=2;i<=n;i++)ans=1ll*ans*i%p;cout<<ans; 
	return 0;
}
