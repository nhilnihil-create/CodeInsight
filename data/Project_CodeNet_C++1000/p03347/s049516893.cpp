#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	lint ans=accumulate(a.begin(),a.end(),0LL);
	int pre=-1;
	rep(i,n){
		if(a[i]-pre>1){
			puts("-1");
			return 0;
		}
		if(pre!=-1 && pre+1==a[i]){
			ans-=pre;
		}
		pre=a[i];
	}
	printf("%lld\n",ans);

	return 0;
}
