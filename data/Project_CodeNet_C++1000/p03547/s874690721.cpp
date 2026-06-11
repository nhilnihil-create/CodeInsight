#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef long double ld;
#define fr first
#define sc second
#define pb push_back
const ll mod = 998244353;
const int N = 1e6+205;
void solve(){
	char x,y;
	cin>>x>>y;
	if(x==y)cout<<"="<<endl;
	if(x>y)cout<<">"<<endl;
	if(x<y)cout<<"<"<<endl;	
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
