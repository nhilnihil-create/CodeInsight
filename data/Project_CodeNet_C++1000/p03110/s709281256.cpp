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
	int n;
	cin >> n;
	
	double x;
	string u;
	double sum = 0.0;

	for (int i = 0; i < n; i++) {
		cin >> x >> u;
		if (u == "JPY") {
			sum += x;
		}
		else {
			sum += x * 380000.0;
		}
	}

	cout << sum << endl;
}