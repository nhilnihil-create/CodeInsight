#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef long double ld;
#define fi first
#define se second
const ll mod = 1e9+7;
const int N = 1e5+5;
ll a[N];int n; 
bool chmn(ll x){
	for(int i=1;i<=n;i++){
		x -=x%a[i];
	}
	if(x>=2)return true;
	return false;
}
bool chmx(ll x){
	for(int i=1;i<=n;i++){
		x -=x%a[i];
	}
	if(x>2)return true;
	return false;
}
void solve(){
	cin>>n; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ll st = 1;
	ll en = 1e18;
	while(st<=en){
		ll mid=  (st+en)/2;
		if(chmn(mid)){
			en = mid-1;
		}
		else{
			st = mid+1;
		}
	}
	ll mn = st;
	st = 1;
	en = 1e18;
	while(st<=en){
		ll mid=  (st+en)/2;
		if(chmx(mid)){
			en = mid-1;
		}
		else{
			st = mid+1;
		}
	}
	ll mx = st-1ll;
	if(mx<mn){
		cout<<-1<<endl;
		return ;
	}
	cout<<mn<<" "<<mx<<endl;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t=1; 
//	cin>>t; 
	while(t--){
		solve();
	}
	return 0;
}
