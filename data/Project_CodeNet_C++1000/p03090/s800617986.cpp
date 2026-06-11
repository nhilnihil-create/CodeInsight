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

void out(vector<ll> a, vector<ll> b) {
	rep(i, a.size())rep(j, b.size()) {
		cout << a[i] << " " << b[j]<<endl;
	}
}



int main() {
	ll N;
	cin >> N;

	ll M = N / 2;

	if (N % 2 == 0) {
		cout << 4 * M*(M-1)/2 << endl;

		vector<vector<ll>> s(M);
		rep(i, M) {
			s[i].push_back(i+1);
			s[i].push_back(N - i);
		}

		rep(i, M) {
			for (ll j = i + 1; j < M; j++) {
				out(s[i], s[j]);
			}
		}

	}

	if (N % 2 == 1) {
		cout << 4 * M*(M - 1)/2 + 2*M<<endl;

		vector<vector<ll>> s(M+1);
		rep(i, M) {
			s[i].push_back(i+1);
			s[i].push_back(N-1 - i);
		}

		s[M].push_back(N);

		rep(i, M+1) {
			for (ll j = i + 1; j < M+1; j++) {
				out(s[i], s[j]);
			}
		}

	}
	
	
	system("PAUSE");
}
