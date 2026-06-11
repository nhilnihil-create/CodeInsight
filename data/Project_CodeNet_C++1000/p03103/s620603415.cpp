#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<functional>
#include<math.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pf(n) printf("%lld\n",n)
#define pff(a,b) printf("%d  %d\n",a,b);
typedef long long ll;
typedef pair<ll, ll> p;
const int INF = 1001001001;
const double PI = acos(-1);

int main() {
	ll n, m;
	cin >> n >> m;
	vector<p> ab(n);
	rep(i, n) cin >> ab[i].first >> ab[i].second;
	sort(ab.begin(), ab.end());
	ll mone = 0;
	for (int i = 0; m > 0; i++) {
		if (ab[i].second >= m) {
			mone += ab[i].first*m;
			m = 0;
		}
		else {
			m -= ab[i].second;
			mone += ab[i].first*ab[i].second;
		}
	}
	pf(mone);


	return 0;
}