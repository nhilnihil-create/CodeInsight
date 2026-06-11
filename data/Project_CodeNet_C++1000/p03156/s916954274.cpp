#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
#define pb push_back
#define fi first
#define se second
const ll mod = 1e9+7;
const int N = 2e6+6;
void solve(){
	int n; 
	cin>>n; 
	vector<int>v(n);
	int a,b; 
	cin>>a>>b; 
	for(int i=0;i<n;i++)cin>>v[i];
	int c[3]={};
	for(int i=0;i<n;i++){
		if(v[i]<=a)c[0]++;
		else if(v[i]<=b)c[1]++;
		else c[2]++;
	}
	cout<<min({c[0],c[1],c[2]})<<endl;
	
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
