#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
int n,l=1,r=3;
ll ans=1e15,a[N],s[N];
ll calc(int l,int r){return s[r]-s[l-1];}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		s[i]=s[i-1]+a[i];
	}
	for(int i=2;i<=n;i++){
		while(l+2<=i&&abs(calc(1,l)-calc(l+1,i))>abs(calc(1,l+1)-calc(l+2,i)))l++;
		while(r+2<=n&&abs(calc(i+1,r)-calc(r+1,n))>abs(calc(i+1,r+1)-calc(r+2,n)))r++;
		ll a=calc(1,l),b=calc(l+1,i),c=calc(i+1,r),d=calc(r+1,n);
		ans=min(ans,max(max(a,b),max(c,d))-min(min(a,b),min(c,d)));
	}
	printf("%lld",ans);
	return 0;
}