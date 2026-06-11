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
	string s;
	cin >> s;
	int n = s.size();
	ll u = 0;
	ll b = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T') {
			b++;
			u = max(u, b);
		}
		else {
			b = 0;
		}
	}
	cout << u << endl;
	return 0;
}
