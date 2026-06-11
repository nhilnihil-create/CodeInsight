#include"bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int N;
	string A, B, C;
	cin >> N >> A >> B >> C;
	int ans = 0;
	rep(i, N) {
		if (A.at(i) != B.at(i) && B.at(i) != C.at(i) && C.at(i) != A.at(i)) ans += 2;
		else if (A.at(i) == B.at(i) && B.at(i) == C.at(i));
		else ans++;
	}
	cout << ans << endl;
	return 0;
}