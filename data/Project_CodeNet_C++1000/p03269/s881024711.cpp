#include <bits/stdc++.h>
#define mod 1000000007
#define pb push_back
#define ll long long
#define mp make_pair
using namespace std;
int main(){
	ll val;
	vector< ll > from,to,cost;
	cin>>val;
	ll cnt = 0, cur =1;
	while(cur*2<=val){
		cur = cur *2;
		cnt++;
	}
	ll n = cnt+1;
	ll m=0;
	for(int i=1;i<=n-1;i++){
		from.pb(i);to.pb(i+1);cost.pb(0);m++;
		from.pb(i);to.pb(i+1);cost.pb( (1<<(i-1)) );m++;
	}
	ll c = val - 1;
	for(int i=n-1;i>=1;i--){
		if( c - (1<<(i-1))+1 >= (1<<(n-1)) ){
			from.pb(i);to.pb(n);cost.pb(c - (1<<(i-1))+1);m++;
			c = c-(1<<(i-1));
		}
	}
	cout<<n<<" "<<m<<endl;
	for(int i=0;i<m;i++){
		cout<<from[i]<<" "<<to[i]<<" "<<cost[i]<<endl;
	}
	return 0;
}