#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,mo=1e9+7;
int a[N],inv[N],s[N];
signed main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	inv[1]=1; for(int i=2;i<=n;i++) inv[i]=1LL*(mo-mo/i)*inv[mo%i] %mo;
	s[1]=1;for(int i=2;i<=n;i++) s[i]=(s[i-1]+inv[i])%mo;
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=(ans+1LL*(s[n-i+1]+s[i]-1)%mo*a[i])%mo;
	}
	for(int i=1;i<=n;i++)
		ans=1LL*ans*i%mo;
	cout<<ans;
	return 0;
}