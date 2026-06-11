#include "bits/stdc++.h"
using namespace std;
int ans;
long long N;
bool check753(long long n) {
	int th = false;
	int fi = false;
	int se = false;
	while (n != 0) {
		if (3 == n%10) {
			th = true;
		}
		if (5 == n%10) {
			fi = true;
		}
		if (7 == n%10) {
			se = true;
		}
		n /= 10;
	}
	if (th && fi && se) {
		return true;
	}
	return false;
}
void dfs(long long v) {
	if (N < v) {
		return;
	}
	if (check753(v)) {
		ans++;
	}
	dfs(10 * v + 7); 
	dfs(10 * v + 5); 
	dfs(10 * v + 3);
}

int main() {
	cin >> N;
	ans = 0;
	dfs(0);
	cout << ans <<  endl;
	return 0;
}