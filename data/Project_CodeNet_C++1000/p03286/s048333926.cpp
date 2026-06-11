#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef long double ld;
#define pb push_back
#define fi first
#define se second
const ll mod = 1e9+7;
char g[101][101];
int dp[101][101];
void solve(){
	string s = "";
	int n; 
	cin>>n; 
	if(n==0){
		cout<<0<<endl;
		return ;
	}
	while(n){
		if(n%2!=0){
			s+='1';
			n--;
		}
		else{
			s+='0';
		}
		n*=-1;
		n/=2;
	}
	reverse(s.begin(),s.end());
	cout<<s<<endl;
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

/*
5 5
#####
#.#.#
####.
#.#.#
###.#
*/




/// 1100111011
/// 0123456789
/// 00000000001
