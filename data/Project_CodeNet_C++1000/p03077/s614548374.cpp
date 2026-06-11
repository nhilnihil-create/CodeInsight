#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define SZ(x) ((int)(x.size()))
#define FOR(i,s,n) for (ll i = (s); (i) < (n); ++i)
#define FORD(i,s,l) for (ll i = (s); (i) >= l; --i)
#define F first
#define S second
#define TC int __tc; cin >> __tc; FOR(case_num,1,__tc+1)
#define TEST(x,i) ((x)&(1ll<<(i)))
#define SET(x,i) ((x)|(1ll<<(i)))
#define FLIP(x,i) ((x)^(1ll<<(i)))
#define CLEAR(x,i) ((x)&~(1ll<<(i)))

const double pi = 4 * atan(1);
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;
const int MAXN = 200005;

ll ceilDiv(ll a, ll b) {
	return a / b + (a % b != 0);
}

ll a[5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll n;
	cin >> n;

	
	FOR(i,0,5)
	{
		cin >> a[i];
	}

	ll low = a[0];
	FOR(i,0,5) {
		low = min(low,a[i]);
	}

	cout << 5+(ceilDiv(n,low)-1) << "\n";
}
