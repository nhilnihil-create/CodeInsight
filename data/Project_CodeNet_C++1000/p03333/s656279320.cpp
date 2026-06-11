#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
#define N 100050
ll ans;
int l[N],r[N],n;
int main() {
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++) scanf("%d%d",&l[i],&r[i]);
	sort(l,l+n+1); sort(r,r+n+1);
	for(i=0;i<=n;i++) {
		if(l[n-i]<=r[i]) break;
		ans+=l[n-i]-r[i];
	}
	printf("%lld\n",ans<<1);
}