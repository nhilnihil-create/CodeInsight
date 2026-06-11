#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define v(n) int n; cin>>n;
using namespace std;

int main() {
	v(a); v(b);
	if (a % b == 0) cout << -1 << endl;
	else {
		int o;
		for (int i = 0; i < i + 1; i++) {
			o = a * (i + 1);
			if (o % b != 0) break;
		}
		cout << o << endl;
	}
}