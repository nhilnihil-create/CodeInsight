#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int N=200100;
inline int read(){
	int x=0,f=0,c=getchar();
	for(;c>'9'||c<'0';f=c=='-',c=getchar());
	for(;c>='0'&&c<='9';c=getchar())
	x=(x<<1)+(x<<3)+c-'0';return f?-x:x;
}
inline void write(ll x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);putchar(x%10+'0');
}
ll n;
ll ans=9e18,a[N],res,x;
int main(){
	ll i,k,c;
	n=read();x=read();
	for(i=1;i<=n;i++)a[i]=read()+a[i-1];
	for(k=1;k<=n;k++){
		res=0;c=3;
		for(i=n;i>0;i-=k){
			res+=max(c,5ll)*(a[i]-a[max(i-k,0ll)]);
			c+=2;
			if(res>=ans)break;
		}
		res+=x*(k+n);
		ans=min(ans,res);
	}write(ans);puts("");
	return 0;
}