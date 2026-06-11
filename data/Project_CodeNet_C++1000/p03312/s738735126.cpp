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
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

int n;
ll a[200005],rui[200005];

int main(){
	cin >> n;
	repn(i,n) cin >> a[i];
	repn(i,n) rui[i] = rui[i-1] + a[i];
	
	ll ans = 1e18;
	
	for(int i=2;i<=n-2;i++){
		int x = lower_bound(rui+1,rui+n+1,rui[i]/2)-rui;
		int y = lower_bound(rui+1,rui+n+1,rui[i]+(rui[n]-rui[i])/2)-rui;

		for(int a=x-3;a<=x+3;a++){
			for(int b=y-i-3;b<=y-i+3;b++){
				if(1 <= a && a < i && 1 <= b && b < n-i){
					ll p = rui[a];
					ll q = rui[i] - rui[a];
					ll r = rui[i+b] - rui[i];
					ll s = rui[n] - rui[i+b];
					
					ll mx = max(max(p,q),max(r,s));
					ll mn = min(min(p,q),min(r,s));
					ans = min(ans,mx-mn);
				}
			}
		}
	}
	cout << ans << endl;
}