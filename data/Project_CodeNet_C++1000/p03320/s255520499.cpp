#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
typedef pair<ll,ll> Q;
typedef pair<Q,ll> R;
vector<pair<ll,int>>ret;
vector<ll>ans;
int k;
void make(ll cur,int num,int zan){
    if(zan == 0){
		ret.pb(mp(cur,num));
		return;
	}
    if(cur >= 100) make(cur*10LL+9,num+9,zan-1);
    else for(int i=(cur==0?1:0);i<10;i++) make(cur*10LL+i,num+i,zan-1);
}
int main(){
	repn(d,15){
		make(0,0,d);
	}
	SORT(ret); ERASE(ret);
	rep(i,ret.size()){
		for(int j=i+1;j<ret.size();j++){
			ll a = ret[i].fi, b = ret[i].sc;
			ll c = ret[j].fi, d = ret[j].sc;
			//a/b > c/d?
			if(a*d > b*c) goto fail;
		}
		ans.pb(ret[i].fi); fail:;
	}
	int k; cin >> k;
	rep(i,k) cout << ans[i] << endl;
}