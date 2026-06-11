#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
#define FOR(i, a, b) for(ll i=(a); i < (ll)(b); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

int GCD(int a, int b){
	if(b==0) return a;
	
	return GCD(b, a%b);
}

int main(){
	int n;
	cin >> n;
	vector<int> a(n+1); // 1-based
	FOR(i,1,n+1) cin >> a[i];
	
	vector<int> sum(n+2,0),rsum(n+2,0);
	sum[2] = a[1];
	FOR(i,2,n+1) sum[i+1] = GCD(sum[i],a[i]);
	rsum[n-1] = a[n];
	for(int i=n-1; i>=1; i--) rsum[i-1] = GCD(rsum[i],a[i]);
	
	int ans = 0;
	FOR(i,1,n+1){
		chmax(ans, GCD(sum[i],rsum[i]));
	}
	
	cout << ans << endl;
	
	return 0;
}