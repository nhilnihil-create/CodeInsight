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
#define pf(n) printf("%d\n",n)
#define pff(a,b) printf("%d  %d\n",a,b);
typedef long long ll;
typedef pair<ll, ll> p;
const int INF = 1001001001;
const double PI = acos(-1);

int main() {
	int n, t, a;
	cin >> n >> t >> a;
	vector<int> h(n);
	rep(i, n) cin >> h[i];

	double mi = 1001001;
	int ans = 0;
	rep(i, n) {
		double tmp = abs(a - t + h[i] * 0.006);
		if (mi > tmp) {
			ans = i + 1;
			mi = tmp;
		}
	}
	cout << ans << endl;

	return 0;
}