#include <iostream>

using namespace std;

int N, total=0;

void dfs(long long n, unsigned char flag357) {
	if (n <= N) {
		if (flag357 == 07)
			total++;
		dfs(n * 10 + 3, flag357 | 01);
		dfs(n * 10 + 5, flag357 | 02);
		dfs(n * 10 + 7, flag357 | 04);
	}
}

int main() {
	cin >> N;
	dfs(0, 0);
	cout << total << endl;


	return 0;
}