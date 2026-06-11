#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef long double ld;
#define pb push_back
#define fi first
#define se second
const ll mod = 1e9+7;
const int N = 2e5+5;
ll cnt[N][33];
void solve(){
	int n,m; 
	cin>>n>>m; 
	for(int i=0;i<n;i++){
		int x,y,c; 
		cin>>x>>y>>c;
		cnt[x+x-1][c]++;
		cnt[y+y][c]--;
	}
	ll mx = 0;
	for(int j=1;j<=m;j++){
		for(int i=1;i<N;i++){
			cnt[i][j]+=cnt[i-1][j];
		}
	}
	for(int i=1;i<N;i++){
		ll trt = 0;
		for(int j=1;j<=m;j++){
			if(cnt[i][j])trt++;
		}
		mx=  max(mx,trt);
	}
	cout<<mx<<endl;
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
