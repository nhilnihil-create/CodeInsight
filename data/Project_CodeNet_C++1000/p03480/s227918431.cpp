#include <iostream>
#include <string>
#include <cmath>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<iomanip>
#define _USE_MATH_DEFINES
#include <math.h>
#include <functional>
using namespace std;

#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)

typedef long long ll;
const ll INF = 1e17;
const ll MOD = 1000000007;
const ll MAX = 1000001;

ll max(ll a, ll b) {
	if (a > b) { return a; }
	return b;
}

ll min(ll a, ll b) {
	if (a > b) { return b; }
	return a;
}

ll gcd(ll a, ll b) {
	if (b == 0) { return a; }
	if (a < b) { return gcd(b, a); }
	return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}

struct edge {
	ll ind;
	ll fr;
	ll to;
	ll d;
};


///////////////////////////


int main() {

	string S;
	cin >> S;

	ll N = S.size();

	vector<ll> a(N+1,0);

	rep(i, N) a[i] = S[i] - '0';

	vector<ll> b(N + 1, 0);

	b[0] = a[0];

	repn(i, N) {
		if (a[i] != a[i - 1]) { b[i] = 1; }
	}

	ll ans = N;
	
	rep(i, N + 1) {
		if (b[i] == 0) { continue; }

		ll d = max(i, N - i);
		ans = min(d, ans);
	}

	cout << ans;



	system("PAUSE");

	

}
