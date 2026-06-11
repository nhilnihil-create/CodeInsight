#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	int ans = 1;
	set<int>S; 
	S.insert(N);
	while (true) {
		++ans;
		int num = S.size();
		if (1 == N%2) {
			N = 3 * N + 1;
		}
		else {
			N /= 2;
		}
		S.insert(N);
		if (num ==S.size()) {
			break;
		}
	}
	cout << ans << endl;
}