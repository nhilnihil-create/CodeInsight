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
ll a[200010];ll qz[200010],ret;
int main(){
	n=r;m=r;ret=10000000000000000ll;
	for(rt i=1;i<=n;i++)a[i]=r,qz[i]=qz[i-1]+a[i];
	for(rt i=n;i>=1;i--){
		ll now=(ll)m*i;
		for(rt j=1,R=n;R;j++){
			int L=max(1,R-i+1);
			now+=(qz[R]-qz[L-1])*max(j*2+1,5);
			if(now>ret)break;
			R=L-1;
		}
		ret=min(ret,now);
	}
	cout<<ret+1ll*n*m;
	return 0;
}
