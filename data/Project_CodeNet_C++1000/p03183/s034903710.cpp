#include<bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
#define F first
#define S second
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long 
#define ld long double
#define bug(x)  cout<<"passed "<<x<<endl;
long long const inf = 1e18, linf = 1e9, mod = 1e9+7;
int const mxn = 1e3+10;
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
///////////////////////////////////
long long n,ans;
long long dp[mxn*30];
vector <pair <pair <int ,int > , pair <int ,int > > > vec;
//////////////////////////////////



int main(){
	cin>>n;
	for (int i= 0;i<n;i++){
		int w , m , v;
		cin>>w>>m>>v;
		vec.push_back({{w+m,v} , {w,m}});
	}
	sort(vec.begin() , vec.end());
	for (int i = 1;i<=n;i++){
		int w = vec[i-1].S.F , m = vec[i-1].S.S , v = vec[i-1].F.S;
		for(int j = 20000;j>=0;j--){
			if (j<=m)
				dp[j+w] = max(dp[j+w] , dp[j]+v);
			ans = max(ans, dp[j+w]);
		}
	}
	cout<<ans;	
}
/*
3
2 2 20
2 1 30
3 1 40
*/