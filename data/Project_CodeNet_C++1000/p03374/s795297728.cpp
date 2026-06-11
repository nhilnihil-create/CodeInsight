

#include<iostream>
#include<cstdio>
#include<cstring>
#include <cstdlib>  
#include <cmath>   
#include<cctype>
#include<string>
#include<set>
#include <map>
#include<algorithm>
#include <functional>
#include<vector>
#include<climits>
#include<stack>
#include<queue>
#include <deque>
#include <climits>
#include <typeinfo>
#include <utility> 
#define all(x) (x).begin(),(x).end()
#define rep(i,m,n) for(int i = m;i < n;++i)
#define rrep(i,m,n) for(int i = m;i >= n;--i)
#define INF INT_MAX/2
using namespace std;
using ll = long long;
using R = double;
const ll inf = 1LL << 50;
const ll MOD = 1e9 + 7;
struct edge { ll from; ll to; ll cost; };

void chmax(ll &a,ll b) {
	if (a < b)a = b;
}

ll n, c;
ll x[101010], v[101010];
ll y[101010];
ll A[101010], B[101010], D[101010];

ll solve() {
	A[0] = v[0];
	rep(i, 1, n)A[i] = A[i - 1] + v[i];
	rep(i, 0, n)y[i] = c - x[i];
	B[n - 1] = v[n - 1];
	rrep(i, n - 2, 0)B[i] = B[i + 1] + v[i];
	D[n - 1] = B[n - 1] - y[n - 1];
	rrep(i, n - 2, 0) {
		D[i] = B[i] - y[i];
		chmax(D[i], D[i + 1]);
	}
	ll ans = 0;
	rep(i, 0, n) {
		ll sm = 0;
		sm -= x[i];
		sm += A[i];
		chmax(ans, sm);
		sm -= x[i];
		if (i < n - 1)sm += D[i + 1];
		chmax(ans, sm);
	}

	return ans;
}


int main(){
	cin >> n >> c;

	rep(i, 0, n)cin >> x[i] >> v[i];

	ll ans = 0;
	chmax(ans, solve());

	reverse(v, v + n);
	rep(i, 0, n)x[i] = c - x[i];
	reverse(x, x + n);

	chmax(ans, solve());
	cout << ans << endl;
	
	return 0;
}