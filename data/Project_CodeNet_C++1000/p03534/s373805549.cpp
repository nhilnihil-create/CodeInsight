#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> VI;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, ll, ll> t4;

#define rep(a,n) for(ll a = 0;a < n;a++)
#define repi(a,b,n) for(ll a = b;a < n;a++)

static const ll INF = 1e15;

int main(void)
{
	string s;
	cin >> s;
	int cs[3] = {0,0,0};
	int n = s.size();
	for (char c : s) {
		int index = c - 'a';
		cs[index]++;
	}
	bool ok = true;
	for (int i = 0; i < 3; i++) {
		if (abs(cs[i] - cs[(i + 1) % 3]) > 1) {
			ok = false;
		}
	}
	if (ok) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}
