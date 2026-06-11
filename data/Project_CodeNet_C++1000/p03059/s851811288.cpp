#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int A, B, T;
	cin >> A >> B>> T ;

	int ans = 0;
	int cnt = 0;
	while (true) {
		cnt += A;
		if (cnt > T){
			break;
		}
		ans += B;
	}

	cout << ans << "\n";

	return 0;
}
