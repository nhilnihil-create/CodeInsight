#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i,n) for(ll i=0;i<n;i++)

int main(){
	int n;cin>>n;
	ll a[n],b[n],suma=0,sumb=0;
	rep(i,n) {
		cin>>a[i];
		suma+=a[i];
	}
	rep(i,n) {
		cin>>b[i];
		sumb+=b[i];
	}
	if(suma<sumb){
		cout<<-1<<"\n";
		return 0;
	}

	ll cnt=0,minus=0;
	vector<ll> plus;
	rep(i,n){
		if(a[i]<b[i]){
			cnt++;
			minus+=b[i]-a[i];
		}
		else if(a[i]>b[i]){
			plus.push_back(a[i]-b[i]);
		}
	}
	int lp=plus.size();
	sort(plus.begin(),plus.end());
	reverse(plus.begin(),plus.end());
	
	//cout<<lp<<"\n";

	rep(i,lp){
		if(minus<=0) break;
		minus-=plus[i];
		cnt++;
	}

	cout<<cnt<<"\n";
}