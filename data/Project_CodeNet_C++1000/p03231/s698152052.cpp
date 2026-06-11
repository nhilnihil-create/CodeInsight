#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

int gcd(int x, int y) {
	if(y == 0) return x;
	else return gcd(y, x % y);
}

int main() {
	long long n, m; cin >> n >> m;
	string s, t; cin >> s >> t;
	long long l = n / gcd(n, m) * m;

	long long a = l / n, b = l / m;
	long long c = a / gcd(a, b) * b;

	long long i = 0;
	bool ok = true;
	while (i < l)
	{
		if(s[i / a] != t[i / b]) ok = false;
		i += c;
	}

	if(ok) cout << l << endl;
	else cout << "-1" << endl;
	return 0;
}
