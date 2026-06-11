#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<string> W(N);
	for (int i = 0; i < N; i++) cin >> W[i];
	string ans = "Yes";
	map<string, bool> M;
	for (int i = 0; i < N - 1; i++) {
		if (M[W[i + 1]]) ans = "No";
		int num = W[i].size() - 1;
		if (W[i][num] != W[i + 1][0]) ans = "No";
		M[W[i]] = true;
	}
	cout << ans << endl;
	return 0;
}