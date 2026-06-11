#include <bits/stdc++.h>
using namespace std;
int64_t l[100005],n,r[100005],ans;
int main(){
	cin>>n;
	for(int i=0;i<n;++i) cin>>l[i]>>r[i];
	sort(l,l+n+1,greater<long long>());sort(r,r+n+1);
	for(int64_t i=0,sum=0;i<=n;++i){
		sum += 2*(l[i]-r[i]);
		ans = max(ans,sum);
	}
	cout<<ans;
}