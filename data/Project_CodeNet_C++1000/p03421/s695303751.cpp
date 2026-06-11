#include <bits/stdc++.h>
#define mod 1000000007
#define pb push_back
#define ll long long
#define mp make_pair
using namespace std;
int main(){
	ll n,a,b;
	cin>>n>>a>>b;
	if( a+b > n+1){
		cout<<-1<<endl;
		return 0;
	}
	else if( a*b < n){
		cout<<-1<<endl;
		return 0;
	}
	else{
		vector<ll> ans;
		ll lef = n;
		for(int i=0;i<b;i++){
			ans.pb(1);
			lef--;
		}
		for(int i=0;i<b;i++){
			ll tmp = min( lef, a-1 );
			ans[i] += tmp;
			lef -= tmp;
		}
		ll cur = n;
		for(int i=0;i<b;i++){
			cur = cur-ans[i]+1;
			for(int j=0;j<ans[i];j++){
				cout<<cur+j<<" ";
			}
			cur--;
		}
		cout<<endl;
		return 0;
	}
	return 0;
}