#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef long double ld;
#define pb push_back
#define fi first
#define se second
const ll mod = 1e9+7;
const int N = 303+5;
int a[N][N];
int px[N*N];
int py[N*N];
int dis[N*N];
void solve(){
	int n,m,d; 
	cin>>n>>m>>d;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			px[a[i][j]]=i;
			py[a[i][j]]=j;
		}
	}
	for(int i=0;i<d;i++){
		dis[i] = 0;
	}
	for(int i=d;i<=n*m;i++){
		dis[i] = 1e9;
	}
	for(int i=d;i<=n*m;i++){
		dis[i] = dis[i-d]+abs(px[i]-px[i-d])+abs(py[i]-py[i-d]);
	}
	int q;
	cin>>q;
	while(q--){
		int l,r; 
		cin>>l>>r;
		cout<<dis[r]-dis[l]<<endl;
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
