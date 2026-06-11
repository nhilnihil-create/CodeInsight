#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	string ans = "";
	while (N!= 0) { 
		int r = N % 2;
		if (r < 0) {
			r += 2;
		}
		N = (N - r) / (-2);

		ans += (char)(r + '0');
	}
	reverse(ans.begin(),ans.end());
	if (ans == "") {
		ans = "0";
	}
	cout << ans <<endl;
	return 0;
}
