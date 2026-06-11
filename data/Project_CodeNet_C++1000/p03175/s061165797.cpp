#include <cmath>
#include <cstdio>
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <stack>
#include <fstream>
#include <queue>
#include <iomanip>
#include <iterator>
#include <map>
#include <unordered_map>
#include <set>
#define fast ios_base::sync_with_stdio(false)
#define mxn (ll)1e5
#define mod (ll)(1e9+7)
#define mod1 (ll)(998244353)
#define ll long long int
#define ld long double
#define vi vector<ll>
#define vvi vector<vi >
#define pi pair<ll,ll>
#define vvpi vector<vector<pi > >
#define vpi vector<pi >
#define vppi vector<pair<ll,pi > >
#define vs vector<string>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define pb push_back
#define eb emplace_back
#define mkp make_pair
#define fs first
#define se second
#define crz(v,n) v.clear(),v.resize(n+1,0)
#define print(v) for(ll it=0;it<v.size();it++) cout<<v[it]<<" ";cout<<endl
#define printp(v) for(ll it=0;it<v.size();it++) cout<<v[it].first<<" "<<v[it].second<<endl
using namespace std;
vpi d(mxn+5);vvi g(mxn+5);
pi dfs(int i,int p){
	d[i].fs=d[i].se=1;
	for(auto j:g[i]) if(j-p){
		pi a=dfs(j,i);
		d[i].fs=(d[i].fs*(a.fs+a.se))%mod;
		d[i].se=(d[i].se*a.fs)%mod;
	}return mkp(d[i].fs,d[i].se);
}
int main(){
	int n,i,u,v;cin>>n;
	for(i=1;i<n;i++) cin>>u>>v,g[u].pb(v),g[v].pb(u);
	dfs(1,0);
	cout<<(d[1].fs+d[1].se)%mod;
}

