#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],sum[200010],x[200010],l,r,ans;
int main(){
	long long i,j;
	cin>>n;
	sum[0]=0;
	x[0]=0;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	x[1]=a[1];
	for(i=2;i<=n;i++)x[i]=x[i-1]^a[i];
	l=1;
	for(r=1;r<=n;r++){
		while(sum[r]-sum[l-1]!=(x[r]^x[l-1]))l++;
		ans+=r-l+1;
	}
	cout<<ans<<'\n';
	return 0;
}