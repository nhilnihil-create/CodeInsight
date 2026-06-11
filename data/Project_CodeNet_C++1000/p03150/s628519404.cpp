#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
#define pb push_back
#define fi first
#define se second
const ll mod = 1e9+7;
const int N = 2e5+6;
void solve(){
	string s; 
	cin>>s; 
	bool ans = false;
	int n = s.size();
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			string ss = s.substr(0,i);
			ss+=s.substr(j,n-j);
			if(ss=="keyence"){
				ans = true;
			}
		}
	}
	if(ans)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
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
