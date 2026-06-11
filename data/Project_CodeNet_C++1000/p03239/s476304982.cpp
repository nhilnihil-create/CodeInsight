#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int N, T;
	cin >> N >> T;

	int ans = 100100100;
	for (int ii = 0; ii < N; ++ii){
		int c, t;
		cin >> c >> t;
		if (t <= T){
			ans = min(ans, c);
		}
	}

	if (ans == 100100100){
		cout << "TLE" << endl;
	} else {
		cout << ans << endl;
	}


	return 0;
}
