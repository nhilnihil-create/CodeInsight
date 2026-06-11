#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[114514],b[114514],x[114514];
int main(){
	ll n;
	cin>>n;
	ll suma=0,sumb=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		suma+=a[i];
	}
	ll num=0,ans=0;
	for(int i=0;i<n;i++){
		cin>>b[i];
		sumb+=b[i];
		x[i]=a[i]-b[i];
		if(x[i]<0){
			num-=x[i];
			ans++;
		}
	}
	if(suma<sumb){
		cout<<-1;
		return 0;
	}
	sort(x,x+n);
	ll i=n-1;
	while(1){
		if(num<=0){
			cout<<ans;
			return 0;
		}
		num-=x[i];
		i--;
		ans++;
	}
	return 0;
}