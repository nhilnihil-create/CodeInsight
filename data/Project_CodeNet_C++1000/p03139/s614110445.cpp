#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int N, A, B;
	cin >> N >> A >> B;

	int ans1 = min(A, B);
	int ans2 = max(0, A + B - N);

		cout << ans1 << " ";
		cout << ans2 << "\n";		

	return 0;
}
