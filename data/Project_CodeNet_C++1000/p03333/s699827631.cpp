#include<bits/stdc++.h>
using namespace std;
const int N=100005;
typedef long long ll;
int n,l[N],r[N];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)scanf("%d%d",&l[i],&r[i]);
	sort(l,l+n+1);
	reverse(l,l+n+1);
	sort(r,r+n+1);
	ll ans=0;
	for (int i=0;i<n;i++){
		ll c=l[i]-r[i];
		if (c<=0)break;
		ans+=2*c;
	}
	printf("%lld\n",ans);
}
