#include"bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int digits(int x) {
	return x / 10000 + x % 10000 / 1000 + x % 1000 / 100 + x % 100 / 10 + x % 10;
}

int main(){
	int N;
	cin >> N;
	int ans = -1;
	for (int i = 1;i <= (N + 1)/2;++i) {
		if (ans < 0) {
			ans = digits(i) + digits(N - i);
		}
		else if (digits(i) + digits(N - i) < ans) {
			ans = digits(i) + digits(N - i);
		}
	}
	cout << ans << endl;
	return 0;
}