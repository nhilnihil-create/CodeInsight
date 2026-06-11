#include<iostream>
#include<algorithm>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
using namespace std;
typedef long long ll;

ll fabs(ll a){
	if(a<0)return -a;
	return a;
}

int main(){
	int n;
	cin>>n;
	ll a[n];
	rep(i,n){
		cin>>a[i];
		a[i]-=i;
	}
	sort(a,a+n);
	ll ans=0;
	rep(i,n)ans+=fabs(a[i]-a[n/2]);
	cout<<ans<<endl;
	return 0;
}