#include "bits/stdc++.h"

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define bit(n) (1LL << (n))
#define sz(x) ((int)(x).size())
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define en '\n'
#define pb push_back
#define P pair<int, int>

typedef long long ll;
using namespace std;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll g = gcd(a, b); return a / g * b; }
const int dx[4] = { 1, 0, -1,  0 };
const int dy[4] = { 0, 1,  0, -1 };
const int INF = (int)1e9;
const ll  inf = (ll)1e18;
const int mod = 1000000007;

int main() {
	ll yy, mm, dd;
	
	string s;
	cin >> s;
	
	yy = stoi(s.substr(0, 4));
	mm = stoi(s.substr(5, 2));

	bool preTime = true;

	if (yy > 2019) preTime = false;
	else if (mm > 4) preTime = false;

	if (preTime) {
		cout << "Heisei" << endl;
	}
	else {
		cout << "TBD" << endl;
	}

	return 0;
}