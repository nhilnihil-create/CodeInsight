#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>

using namespace std;

int main() {
	vector<string> c(3);
	string ans;
	for (int i = 0; i < 3; i++) cin >> c[i];
	for (int i = 0; i < 3; i++) {
		ans.push_back(c[i][i]);
	}
	cout << ans << endl;
	return 0;
}