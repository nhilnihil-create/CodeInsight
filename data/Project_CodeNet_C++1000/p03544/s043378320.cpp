#include <bits/stdc++.h>
using namespace std;

int main() {
	long long int N, ans,bef;
	cin >> N;
	if (N == 1) {
		ans = 1;
	}
	else {
		ans = 1;
		bef = 2;
		for (int i = 0; i < N-1; i++) {
			long long int tmp = ans;
			ans += bef; //最初:2
			bef = tmp;
		}
	}
	cout << ans << endl;
}