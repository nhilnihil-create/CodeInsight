#include <iostream>
#define ll long long

using namespace std;

ll N, ans;

void dfs(ll num, int three, int five, int seven) {
	if (num > N) return;
	if (three * five * seven > 0) ans++;

	dfs(10 * num + 3, 1, five, seven);
	dfs(10 * num + 5, three, 1, seven);
	dfs(10 * num + 7, three, five, 1);

	return;
}

int main() {
	cin >> N;
	dfs(0, 0, 0, 0);
	cout << ans;
}