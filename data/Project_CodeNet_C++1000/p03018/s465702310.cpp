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

#include <bits/stdc++.h>
using namespace std;

static const ll INF = 1e15;

static const ll mod= 1e9 + 7;

int main() {
	string s;
	cin >> s;
	int n = s.size();
	vector<char> cs;
	cs.reserve(n);
	rep(i, n - 1) {
		if (s[i] == 'B' && s[i + 1] == 'C') {
			cs.push_back('D');
			i++;
			continue;
		}
		else {
			cs.push_back(s[i]);
		}
	}
	auto csSize = cs.size();
	ll total = 0;
	int aCount = 0;
	rep(i, csSize) {
		if (cs[i] == 'A') {
			aCount++;
		}
		else if (cs[i] == 'D') {
			total += aCount;
		}
		else {
			aCount = 0;
		}
	}
	cout << total << endl;
	return 0;
}
	