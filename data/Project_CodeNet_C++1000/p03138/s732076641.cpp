#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll a[114514];
ll cnt[50],be[50];
bool f[50];
int main(){
	ll n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		ll x=1;
		for(int j=0;j<40;j++){
			if(j)x=x<<1;
			be[j]=x;
			if(a[i]&x)cnt[j]++;
		}
	}
	for(int i=0;i<40;i++)if(cnt[i]>n/2)f[i]=1;
	ll ans=0,num=k+1;
	for(int i=0;i<40;i++){
		ll sum=0,x=be[i];
		if(i){
			if(f[i-1]&&(num&be[i-1]))num-=be[i-1];
			if(!f[i-1]&&!(num&be[i-1]))num+=be[i-1];
		}
		if(!(num&x))continue;
		num-=x;
		for(int j=0;j<n;j++)sum+=(a[j]^num);
		ans=max(sum,ans);
	}
	cout<<ans;
	return 0;
}
