#include <bits/stdc++.h>
using namespace std;

#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)

typedef long long ll;
const ll INF = 1e17;
const ll MOD = 1000000007;
const ll MAX = 1000001;

ll max(ll a, ll b) {
	if (a > b) { return a; }
	return b;
}

ll min(ll a, ll b) {
	if (a > b) { return b; }
	return a;
}

ll gcd(ll a, ll b) {
	if (b == 0) { return a; }
	if (a < b) { return gcd(b, a); }
	return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}

struct edge {
	ll ind;
	ll to;
	ll d;
};


///////////////////////////


int main() {

	ll N;
	cin >> N;
 
	vector<ll> t(N + 1);
	vector<ll> v(N + 1);
 
	repn(i, N) cin >> t[i];
	repn(i, N) cin >> v[i];
 
	double dp[200][200];
 
	rep(i, N+1)rep(j, 200) { dp[i][j] = -1; }
 
	dp[0][0] = 0;
 
	repn(i, N)rep(j,200) {
		if (j > v[i]) {continue; }
 
		
		rep(k, 200) {
			if (k > v[i]) { continue; }
			if (dp[i - 1][k] == -1) { continue; }
			if (abs(k-j)>t[i]) { continue; }
 
			double sp = min((double)(t[i] + j + k) / 2.0, double(v[i]));
 
			double x = (double)t[i] * sp - (sp - (double)k)*(sp- (double)k) / 2.0 - (sp - (double)j)*(sp - (double)j) / 2.0;
 
			dp[i][j] = max(dp[i][j], dp[i - 1][k] + x);
 
			//cout << i << j << x <<" "<<dp[i][j]<< endl;
		}
 
		//cout << i << j << " " << dp[i][j] << endl;
 
	}
 
	cout << fixed << setprecision(10);
 
	cout << dp[N][0];
	
	
 
	

}
