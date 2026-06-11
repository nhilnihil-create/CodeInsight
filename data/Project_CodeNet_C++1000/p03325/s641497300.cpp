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
typedef long long ll;
typedef pair<ll, ll> p;
const int INF = 1001001001;
const double PI = acos(-1);

ll yaku(ll a) {
	ll cnt = 0;
	//if (a % 2 != 0) return 0;

	while (a % 2 == 0 ) {
		cnt++;
		a /= 2;
	}
	return cnt;
}


int main() {
	ll n;
	cin >> n;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	//pf(yaku(n));

	ll y = 0;
	rep(i, n) {
		y += yaku(a[i]);
		//pf(yaku(a[i]));
	}

	cout << y << endl;


	return 0;
}