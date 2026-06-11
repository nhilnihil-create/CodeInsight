#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef long double ld;
#define fi first
#define se second
const ll mod = 1e9+7;
const int N = 1e5+5;
void solve(){
	int n; 
	cin>>n; 
	int nn =n; 
	int sm = 0;
	while(nn){
		sm+=nn%10;
		nn/=10;
	}
	if(n%sm==0){
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}
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
