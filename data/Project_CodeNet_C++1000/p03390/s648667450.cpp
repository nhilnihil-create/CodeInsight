#include <bits/stdc++.h>
#define mod 1000000007
#define pb push_back
#define ll long long
#define mp make_pair
using namespace std;
ll getma(ll x, ll y){
	if(y<=x){
		return x*y;
	}
	else{
		if( (x+y)%2 == 0){
			return (x+y)*(x+y)/4;
		}
		else{
			return (x+y-1)*(x+y+1)/4;
		}
	}
}
ll solve(ll a, ll b){
	if(a>b) return solve(b,a);
	ll ans = 0;
	ans += a-1;
	ll lef = 0, rig = b;
	while(rig-lef>1){
		ll mid = (rig+lef)/2;
		if( getma(a+1,mid) < a*b){
			lef = mid;
		}
		else{
			rig = mid;
		}
	}
	ans += lef;
	return ans;
}
int main(){
	ll q;
	cin>>q;
	for(int i=0;i<q;i++){
		ll a,b;
		cin>>a>>b;
		cout<<solve(a,b)<<endl;
	}
	return 0;
}