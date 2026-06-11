#include<bits/stdc++.h>
#define fo(i,a,b) for(i=a;i<=b;i++)
#define fd(i,a,b) for(i=a;i>=b;i--)
using namespace std;
typedef long long ll;
inline int read(){
	int n=0;char c;
	for(c=getchar();c<'0'||c>'9';c=getchar());
	for(;c>='0'&&c<='9';c=getchar()) n=n*10+c-48;
	return n;
}
const int maxn=2e5+5;
int n,i,j,l,r;ll x[maxn],ans,X,s[maxn],sum,now,k;
int main(){
	n=read(),X=read();
	fo(i,1,n) x[i]=read(),s[i]=s[i-1]+x[i];
	ans=s[n]*5+(X*n<<1);
	fd(i,n-1,1){
		now=X*(i+n);
		for(r=n,k=1;r;r=l,k++){
			l=r-i,l=l>0?l:0;
			sum=s[r]-s[l];
			if (r==n) now+=sum*5;else
			now+=(k<<1|1)*sum;
			if (now>=ans) break;
		}
		ans=now<ans?now:ans;
	}printf("%lld\n",ans);
} 