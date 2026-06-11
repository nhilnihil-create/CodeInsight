#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> VI;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, ll, ll> t4;
typedef tuple<ll, ll, ll, ll, ll> t5;

#define rep(a,n) for(ll a = 0;a < n;a++)
#define repi(a,b,n) for(ll a = b;a < n;a++)

using namespace std;

static const ll INF = 1e15;

int main() {
	ll n;
	cin >> n;
	ll sum = 0;
	for (int i = 1; i <= n; i+=2) {		
		int c = 0;
		for (int j = 1; j <= i; j+=2) {
			if (i % j == 0) c++;
		}
		if (c == 8) sum++;
	}
	cout << sum << endl;

	return 0;
}
