#include <iostream>
#include <vector>
using namespace std;
int main(void) {
	int n, a;
	cin >> n;
	vector<int> slime(n);
	for (int i = 0; i < n; ++i) cin >> slime[i];

	int ans = 0;
	for (int i = 0; i < n - 1; ++i) {
		if (slime[i] == -1) continue;
		if (slime[i] == slime[i + 1]) {
			slime[i + 1] = -1;
			++ans;
		}
	}
	cout << ans << endl;
	return 0;
}