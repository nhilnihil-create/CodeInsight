#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
#define pb push_back
#define fi first
#define se second
const ll mod = 1e9+7;
const int N = 2e6+6;
void solve(){
	string s,t; 
	cin>>s>>t;
	sort(s.begin(),s.end());
	sort(t.begin(),t.end());
	reverse(t.begin(),t.end());
	if(s<t){
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
