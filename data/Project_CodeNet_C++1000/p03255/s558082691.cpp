#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
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
int n;
ll x[200005];
ll rui[200005];
ll X;
int main(){
	scanf("%d%lld",&n,&X);
	for(int i=1;i<=n;i++){
		scanf("%lld",&x[i]);
		rui[i] = rui[i-1]+x[i];
	}
	ll ans = 1e19;;
	for(int i=1;i<=n;i++){
		ll base = X*1LL*(n+i);
		int c = 0;
		for(int j=1;j<=n;j+=i){
			int beg = j, en = j+i-1;
			en = min(en,n);
			en = n+1-en; beg = n+1-beg;
			if(c == 0){
				base += 5LL*(rui[beg]-rui[en-1]);
			}
			else{
				base += 1LL*(3+2*c)*(rui[beg]-rui[en-1]);
			}
			c++;
		}
		ans = min(ans,base);
	}
	cout << ans << endl;
}