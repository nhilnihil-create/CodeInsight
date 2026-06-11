#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define FORD(i,a,b) for(ll i=a;i>=b;i--)
#define ALL(a)  (a).begin(),(a).end()
#define SZ(a) int((a).size())
#define SORT(c) sort((c).begin(),(c).end())
#define PB push_back
#define MP make_pair
#define MEMSET(v, h) memset((v), h, sizeof(v))
#define sqr(x)  ((x) * (x)) 
#define cub(x)  ((x) * (x) * (x))
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
// ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(){
	int n; cin >> n;
	ll a[n],b[n],diff[n];
	FOR(i,0,n-1) cin >> a[i];
	FOR(i,0,n-1) cin >> b[i];
	FOR(i,0,n-1) diff[i] = a[i]-b[i];
	ll minussum = 0;
	sort(diff,diff+n,greater<ll>());
	int ans = 0;
	FOR(i,0,n-1){
		if(diff[i]<0) {
			minussum += diff[i];
			++ans;
		}
	}
	minussum = 0-minussum;
	FOR(i,0,n-1){
		if(diff[i]>0 && minussum>0){
			minussum -= diff[i];
			++ans;
		}
	}

	if(minussum>0) cout << -1 << endl;
	else cout << ans << endl;



}
