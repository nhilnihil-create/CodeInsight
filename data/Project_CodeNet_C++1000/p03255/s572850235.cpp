#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;
long long n,m,i,j,a[400005],s[400005],ans=0x3f3f3f3f3f3f3f3fll;
int main()
{
	cin>>n>>m;
	rep(i,n){
		cin>>a[i];
	}
	reverse(a+1,a+n+1);
	rep(i,n+n){
		s[i]=s[i-1]+a[i];
	}
	rep(i,n){
		long long tmp=n*m+i*m;
		for(j=1;i*(j-1)+1<=n;j++){
			if((ans-tmp)/(s[i*j]-s[i*(j-1)])<(j==1?5:j*2+1)){
				tmp=ans;break;
			}
			tmp+=(j==1?5:j*2+1)*(s[i*j]-s[i*(j-1)]);
		}
		ans=min(ans,tmp); 
	}
	cout<<ans<<endl;
	return 0;
}