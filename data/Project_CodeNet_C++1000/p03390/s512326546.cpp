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
ll calc(ll sum,ll a,ll b){
    if(a > b) return 0;
	ll ret = max(a * (sum-a) , b * (sum-b));
	if(a <= sum/2 && sum/2 <= b){
		ret = max(ret, sum/2 * (sum - sum/2) );
	}
	return ret;
}
int main(){
	int q; cin >> q;
	while(q--){
		ll a,b; cin >> a >> b;
		if(a > b) swap(a,b);
		ll lb = a-1, ub = 2*b+5;
		while(ub-lb > 1){
			ll mid = (lb+ub)/2;
			//1..a-1 a+1...mid
			//mid....b+1 b-1...1
			ll mx = 0;
			if(a-1 <= mid-b){
				mx = max(mx,calc(mid+1,1,a-1));
				mx = max(mx,calc(mid+2,a+1,mid-b+1));
				mx = max(mx,calc(mid+1,mid+2-b,mid));
			}
			else{
				mx = max(mx,calc(mid+1,1,mid-b));
				mx = max(mx,calc(mid,mid-b+1,a-1));
				mx = max(mx,calc(mid+1,a+1,mid));
			}
			
			if(mx < a*b) lb = mid;
			else ub = mid;
		}
		cout << lb-1 << endl;
	}
}