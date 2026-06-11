#include<iostream>
#include<utility>
#include<algorithm>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<ll,pll> plll;

int main(){
	int n;
	cin>>n;
	ll a[n],b[n];
	plll tmp[n];
	rep(i,n){
		cin>>a[i]>>b[i];
		tmp[i].second=pll(a[i],b[i]);
		tmp[i].first=a[i]+b[i];
	}
	sort(tmp,tmp+n);
	ll taka=0,aoki=0;
	for(int i=n-1;i>=0;i--){
		if((n-1-i)%2)aoki+=tmp[i].second.second;
		else taka+=tmp[i].second.first;
	}
	cout<<taka-aoki<<endl;
	return 0;
}