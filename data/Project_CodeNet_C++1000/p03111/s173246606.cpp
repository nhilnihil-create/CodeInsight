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

int N;
int A, B, C;
vector<int> L;

void chmin(int& a, int b) {
	if (a > b) a = b;
}

int rec(int i, int a, int b, int c) {
	if (i == N) {
		if (!a || !b || !c) return INF;
		return abs(a - A) + abs(b - B) + abs(c - C);
	}

	int res = rec(i + 1, a, b, c);

	chmin(res, rec(i + 1, a + L[i], b, c) + (a ? 10 : 0));
	chmin(res, rec(i + 1, a, b + L[i], c) + (b ? 10 : 0));
	chmin(res, rec(i + 1, a, b, c + L[i]) + (c ? 10 : 0));

	return res;
}

int main() {
	cin >> N;
	cin >> A >> B >> C;
	L.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> L[i];
	}
	cout << rec(0, 0, 0, 0) << endl;
}