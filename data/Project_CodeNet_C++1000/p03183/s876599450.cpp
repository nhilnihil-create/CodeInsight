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
#include <assert.h>
#include <numeric>
#define fast ios_base::sync_with_stdio(false)
#define mxn (ll)(2e4+5)
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
struct node{
	int w,s,v;
	bool operator<(const node &a) const{
		return w+s<a.w+a.s;
	}
};
int main(){
	int n,i,j;cin>>n;vector<node>v(n);for(i=0;i<n;i++) cin>>v[i].w>>v[i].s>>v[i].v;
	sort(all(v));vvi d(n+1,vi(mxn,-1));d[0][0]=0;
	for(i=1;i<=n;i++){
		for(j=0;j<mxn;j++){
			if(d[i-1][j]==-1) continue;
			d[i][j]=max(d[i-1][j],d[i][j]);
			if(j+v[i-1].w<mxn&&j<=v[i-1].s) d[i][j+v[i-1].w]=max(d[i][j+v[i-1].w],d[i-1][j]+v[i-1].v);
		}
	}
	//for(i=0;i<n;i++) cout<<v[i].w<<" "<<v[i].s<<" "<<v[i].v<<endl;
	cout<<*max_element(all(d[n]))<<endl;
}
