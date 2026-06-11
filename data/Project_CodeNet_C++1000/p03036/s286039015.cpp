#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 10000000000000000
int main(){
	ll r,d;cin>>r>>d;
	vector<ll> x(11,0);
	cin>>x[0];

	for(ll i=0;i<=9;i++){
		x[i+1]=r*x[i]-d;
		cout<<x[i+1]<<endl;
	}
	
	return 0;
}