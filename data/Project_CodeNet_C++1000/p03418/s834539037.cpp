#include "bits/stdc++.h"
 
using namespace std;
 
//using Matrix = vector< vector<int> >;
typedef long long ll;
typedef pair<int, int> P;
#define fir first
#define sec second
 
const int INF = 1e9 + 10;
//const ll INF = 1e18 + 10LL;
int dx[5] = {0, 0, 1, -1, 0}, dy[5] = {1, -1, 0, 0, 0};
const double EPS = 1e-10;
bool cmp(P a, P b) { return a.second < b.second; } //End sort (Interval scheduling problem)
ll MOD = 1e9 + 7;
 
ll n, k;
 
void solve() {
	ll ans = 0;
	for (ll b = 1; b <= n; b++) {
		ans += n / b * max(0LL, b - k);
		ans += max(0LL, n % b + 1 - k);
	}
 
	if (k == 0) ans -= n;
 
	printf("%lld\n", ans);
}
 
int main(void){
	cin>>n>>k;
 
	solve();
	
	return 0;
}