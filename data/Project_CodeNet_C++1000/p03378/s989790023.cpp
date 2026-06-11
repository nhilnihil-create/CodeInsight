#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef long double ld;
#define pb push_back
#define fi first
#define se second
const ll mod = 1e9+7;
const int N = 1e6+5;
void solve(){
	int n,m,x; 
	cin>>n>>m>>x; 
	int a=0,b=0;
	for(int i=1;i<=m;i++){
		int y ;
		cin>>y; 
		if(y<x)a++;
		else b++;
	}
	cout<<min(a,b)<<endl;
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

///  a2+a1 a3+a1 a4+a1 a5+a1
///  a2+a2 a3+a2 a4+a2 a5+a2
///  a2+a3 a3+a3 a4+a3 a5+a3
/// x1 = 2 , x2 = 5
/// y1 = 1 , y2 = 3
/// 

