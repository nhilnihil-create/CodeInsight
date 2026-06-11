#include <bits/stdc++.h>
#ifdef LOCAL
#include <pprint.hpp>
#endif
#define endl "\n";
#define pb push_back
#define md 1000000007
#define ll long long int
#define all(v) v.begin(),v.end()
ll power(ll a,ll b){ll z=1;while(b){if(b&1){z*=a;z%=md;}a*=a;a%=md;b/=2;}return z%md;}
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n,m,u,v;
vector<vector<ll>> used;
vector<string> s;

int main(){
	//You need to change array size!
	#ifndef LOCAL
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	#endif 
	
	cin>>n>>m;
	s.resize(n);
	used.assign(n,vector<ll>(m,0));
	for(int i=0;i<n;++i)
		cin>>s[i];

	for(int i=n-1;i>=0;--i){
		used[i][m-1]=(s[i][m-1]=='.');
		if((i+1)<n-1 && used[i+1][m-1]==0)
			used[i][m-1]=0;
	}
	for(int j=m-1;j>=0;--j){
		used[n-1][j]=(s[n-1][j]=='.');
		if((j+1)<m-1 && used[n-1][j+1]==0)
			used[n-1][j]=0;
	}
	for(int i=n-2;i>=0;--i){
		for(int j=m-2;j>=0;--j){
			used[i][j] += used[i+1][j] + used[i][j+1];
			if(s[i][j]=='#')
				used[i][j]=0;
			used[i][j]%=md;
		}
	}
	cout<<used[0][0];

	return 0;	
}


