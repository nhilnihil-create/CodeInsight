
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define f(i,a,b) for (int i = a; i < b; i++)

ll gcd(ll a, ll b) { return a?gcd(b%a,a):b; }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	clock_t start = clock();
#endif

	int t; cin >> t;
	stringstream ss;
	f(_,0,t) {
		ll A,B,C,D;	
		cin>>A>>B>>C>>D;
		ll g = gcd(B,D);
		ll m = (B-A%B-1)/g;	
		if (A<B||D<B) ss << "No" << endl;
		else if (B<=C) ss << "Yes" << endl;
		else if ((A+m*g)%B <= C) ss << "Yes" << endl;
		else ss << "No" << endl;
	}
	cout << ss.str();

#ifdef LOCAL
	cout << setprecision(12) << (long double)(clock()-start) / CLOCKS_PER_SEC << endl;
#endif
	
	return 0;
}

