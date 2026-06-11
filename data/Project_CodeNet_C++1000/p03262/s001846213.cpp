#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

const ll INF = 1000000001;

ll gcd(ll a, ll b) {
   if (a % b == 0) {
       return(b);
   } else {
       return(gcd(b, a % b));
   }
}

int main() {
	ll N, X;
	cin >> N >> X;

	vector <ll> x(N+1);
	for (int ii = 0; ii < N; ++ii){
		cin >> x[ii];
	}
	x[N] = X;
	sort(x.begin(), x.end());

	vector <ll> dist(N);
	for (int ii = 0; ii < N; ++ii){
		dist[ii] = x[ii+1] - x[ii];
	}

	//全てのdistの最大公約数を求める
	ll ans = dist[0];
	for (int ii = 1; ii < N; ++ii){
		ans = gcd(ans, dist[ii]);
	}

	cout << ans << "\n";

	return 0;
}
