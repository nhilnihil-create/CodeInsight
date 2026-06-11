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

#define rep(i,x) for(ll i=0;i<x;i++)
#define repn(i,x) for(ll i=1;i<=x;i++)

typedef long long ll;
const ll INF = 1e17;
const ll MOD = 998244353;
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
	return a / gcd(a, b) *b;
}

struct edge {
	ll ind;
	ll fr;
	ll to;
	ll d;
};


///////////////////////////

ll N, A, B;

void solve() {
	if (A + B > N + 1||A*B<N) {
		cout << -1; return;
	}
	
	vector<ll> s(B,0);

	s[0] = A;

	rep(i,N-A){
		s[i % (B - 1) + 1]++;
	}

	ll sum = 0;

	rep(i, B) {
		sum += s[i];

		repn(j, s[i]) {
			cout << N - sum + j << " ";
		}
	}





}


int main() {

	cin >> N >> A >> B;

	solve();


	system("PAUSE");

}



