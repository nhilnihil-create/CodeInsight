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
#define mxn (ll)2e5
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
ll bit[mxn+5];
ll query(ll x){
	ll s=0;for(;x;x-=x&(-x)) s=max(s,bit[x]);
	return s;
}void upd(ll x,ll val){
	for(;x<mxn+5;x+=x&(-x)) bit[x]=max(bit[x],val);
}
int main(){
	int n,i;cin>>n;vi v(n+1),a(n+1),l(n+1,0);for(i=1;i<=n;i++) cin>>v[i];for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=n;i++){
		l[i]=query(v[i])+a[i];
		upd(v[i],l[i]);
	}cout<<*max_element(all(l))<<endl;
}

