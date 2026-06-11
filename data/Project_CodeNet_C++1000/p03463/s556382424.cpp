#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define MOD 1e9+7;
using namespace std;
using ll = long long;

int main() {
	int n, a, b;
	cin >> n >> a >> b;
	if (a % 2 == b % 2) cout << "Alice";
	else cout << "Borys";
	return 0;
}
