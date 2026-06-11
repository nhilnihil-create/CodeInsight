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





///////////////////////////


int main() {
	ll N, K;

	cin >> N >> K;

	vector<pair<ll, ll>> s(N + 1);

	repn(i, N) {
		cin >> s[i].second >> s[i].first;
	}

	sort(++s.begin(), s.end(),greater<pair<ll,ll>>());

	vector<ll> see(N + 1, 0);

	vector<ll> f(N + 1,0);//各ネタで最もおいしい寿司か

	repn(i,N){
		if (see[s[i].second] == 0) {
			f[i] = 1;
			see[s[i].second] = 1;
		}
	}

	//repn(i, N) { cout << s[i].first << s[i].second << f[i] << endl; }

	ll var = 0;

	ll now = 0;

	repn(i, K) {
		if (f[i] == 1) { var++; }
		now += s[i].first;
	}

	now += var * var;

	ll ans = now;

	ll omit = K;//次削る候補

	for (int i = K + 1; i <= N; i++){
		if (f[i] == 0) { continue; }

		while (omit > 0 && f[omit] == 1) { omit--; }
		if (omit == 0) { break; }
		omit--;

		var++;
		now = now - s[omit+1].first + s[i].first + 2 * var - 1;
		ans = max(now, ans);

		//cout << i << omit << now << endl;
	}

	cout << ans;

	system("PAUSE");

}
