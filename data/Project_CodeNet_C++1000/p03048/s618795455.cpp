#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i=0;i<n;i++)
#define REP(i, n) for(int i=1;i<=n;i++)
typedef long long ll;

int main() {
	ll r, g, b, n;
	cin >> r >> g >> b >> n;
	ll count = 0;
	for (int i = 0; i <= 3000; ++i) {
		for (int j = 0; j <= 3000; ++j) {
			ll N = n - i*r- j*g;
			if(N >= 0 && N % b == 0) count++;
		}
	}
	cout << count << endl;
	return 0;
}

