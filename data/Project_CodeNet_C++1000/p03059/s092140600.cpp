#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define iter std::vector<int>::iterator

int main() {
	ios_base ::sync_with_stdio(0);
	cin.tie(0);

	

	int a, b, t; cin >> a >> b >> t;

	t += 0.5;
	int res = 0;
	int a2 = 0;
	while (a2 + a <= t) {
		res += b;
		a2 += a;

	}

	cout << res;
	return 0;	
}