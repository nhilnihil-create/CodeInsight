#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	int ans = 0;
	int maxv = 0;
	for (int n = 0;n<N;++n) {
		int num;
		cin >> num;
		ans += num;
		maxv = max(maxv,num);
	}
	cout << ans - maxv/2 << endl;
}