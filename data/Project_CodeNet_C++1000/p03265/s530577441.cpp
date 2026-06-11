#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef long double ld;
#define pb push_back
#define fi first
#define se second
const ll mod = 1e9+7;
const int N = 2e5+5;
void solve(){
	int x,xx,y,yy;
	cin>>x>>y>>xx>>yy;
	int dx = xx-x;
	int dy = yy-y;
	cout<<xx-dy<<" "<<yy+dx<<" "<<x-dy<<" "<<y+dx<<endl;
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
