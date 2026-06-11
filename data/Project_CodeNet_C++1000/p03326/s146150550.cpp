#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <deque>
#include <numeric>
#include <map>
#include <stack>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF 100000

using namespace std;
 
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

int main () {
    int N, M;
	cin >> N >> M;
	vector<ll> x(N), y(N), z(N);
	rep(i,N) cin >> x[i] >> y[i] >> z[i];
	ll rot[8][3] = { {1,1,1}, {1,1,-1}, {1,-1,1}, {1,-1,-1}, {-1,1,1}, {-1,1,-1}, {-1,-1,1}, {-1,-1,-1}};
	ll ans = 0;
	rep(r, 8) {
		vector<ll> v(N);
		rep (i,N) {
			v[i] = x[i] * rot[r][0] + y[i] * rot[r][1] + z[i] * rot[r][2];
		}
		sort(v.rbegin(), v.rend());
		ll cur = 0;
		rep(i,M) {
			cur += v[i];
		}
		ans = max(ans, cur);
	}
	cout << ans << endl;
    return 0;
}