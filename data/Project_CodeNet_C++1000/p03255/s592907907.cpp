#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N=200005;
int n;
ll x,a[N],p,ans,sum,now;
int main(){
  scanf("%d%lld",&n,&x);
  for (int i=1;i<=n;i++) scanf("%lld",&p),a[i]=a[i-1]+p;
  ans=1e18;
  for (int k=1;k<=n;k++){
  	sum=0;now=3;
  	for (int i=n;i>=1;i-=k){
  		sum+=(a[i]-a[max(0,i-k)])*max(now,5ll),now+=2;
  		if (sum>=ans) break;
	  }
	ans=min(ans,sum+1ll*x*(k+n));
  }
  printf("%lld\n",ans);
  return 0;
}