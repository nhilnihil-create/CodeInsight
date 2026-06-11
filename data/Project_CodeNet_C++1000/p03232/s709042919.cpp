#include<bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define moder 1000000007
using namespace std;
int mypow(int a,int b){
	if(b==0)return 1;
	if(b%2)return mypow(a,b-1)*a%moder;
	return mypow(a,b/2)*mypow(a,b/2)%moder;
}
int kaijo(int n){
	int ans=1;
	for(int i=1;i<=n;i++){
		ans*=i;
		ans%=moder;
	}
	return ans;
}
int n,a[100010],b[100010],nkai;
signed main(){
	cin>>n;
	rep(i,n)cin>>a[i];
	nkai=kaijo(n);
	for(int i=1;i<=n;i++){
		b[i]=mypow(i,moder-2);
		b[i]*=nkai;
		b[i]%=moder;
		b[i]+=b[i-1];
		b[i]%=moder;
	}
	int ans=0;
	rep(i,n){
		ans+=a[i]*b[n-i]+a[i]*b[i+1]-a[i]*b[1];
		ans%=moder;
	}
	cout<<ans<<endl;
	return 0;
}