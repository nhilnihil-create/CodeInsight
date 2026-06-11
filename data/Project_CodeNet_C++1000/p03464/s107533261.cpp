#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ss(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl

using ll = long long;

using namespace std;

const int N = 100111;

int n;
ll m[N];

int main() {
	scanf ("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf ("%lld", m + i);
	ll l, r;
	l = r = 2;
	
	for (int i = n; 1 <= i; --i) {
		ll a = ((l - 1) / m[i]) * m[i] + m[i];
		ll b = (r / m[i]) * m[i];
		
		if (a > b) 
			return printf ("-1\n"), 0;
			
		l = a;
		r = b + m[i] - 1;
	}
	
	printf ("%lld %lld\n", l, r);
	return 0;
}
