#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int N;
	cin >> N;

	vector <int> p(N);
	int ans = 0;
	for (int ii = 0; ii < N; ++ii){
		cin >> p[ii];
		ans += p[ii];
	}

	sort(p.rbegin(), p.rend());
	ans = ans - p[0] + p[0] / 2;



	cout << ans << "\n";

	return 0;
}
