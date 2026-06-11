#include<bits/stdc++.h>
#define fo(i,a,b) for(i=a;i<=b;i++)
#define fd(i,a,b) for(i=a;i>=b;i--)
using namespace std;
typedef long long ll;
const int maxn=1e5+5,mo=1e9+7;
int i,j,n,l,a[maxn],s[maxn],now,re[maxn];
ll ans;
int main(){
	scanf("%d",&n);
	fo(i,1,n) scanf("%d",&a[i]),s[i]=(s[i-1]+a[i])%mo;
	now=s[n-1]-s[1];
	re[1]=re[0]=1;
	fo(i,2,n) re[i]=(ll)(mo-mo/i)*re[mo%i]%mo;
	fo(l,1,n-2){
		ans+=(ll)now*re[l+1]%mo*re[l+2]%mo;
		(now+=s[n-l-1]-s[l+1])%=mo;
	}
	ans<<=1;
	fo(l,1,n-1) ans+=(ll)(s[l]+s[n]-s[n-l])*re[l+1]%mo;
	(ans+=s[n])%=mo;
	fo(l,2,n) ans=ans*l%mo;
	printf("%lld\n",(ans+mo)%mo);
}