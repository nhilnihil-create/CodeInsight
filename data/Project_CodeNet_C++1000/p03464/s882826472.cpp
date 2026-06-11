#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=100000+10;
int n,a[N];
LL chk(LL x){
	for(int i=1;i<=n;i++){
		x=1LL*a[i]*(x/a[i]);
	}
	return x;
}
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(a[n]!=2)return !printf("-1\n");
	vector<LL> ans;

	{
		LL l=0,r=1e18;
		while(r-l>1){
			LL mid=(l+r)/2;
			if(chk(mid)<2) l=mid;
			else r=mid;
		}
		if(chk(r)==2) ans.push_back(r);
	}

	{
		LL l=0,r=1e18;
		while(r-l>1){
			LL mid=(l+r)/2;
			if(chk(mid)>2) r=mid;
			else l=mid;
		}
		if(chk(l)==2) ans.push_back(l);
	}
	if(ans.size()==0) return !printf("-1\n");
	printf("%lld %lld\n", ans[0],ans[1]);
}