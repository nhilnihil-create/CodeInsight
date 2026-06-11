#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>

using namespace std;

int main() {
	vector<int> num(3);
	for (int i = 0; i < 3; i++) cin >> num[i];
	sort(num.begin(), num.end(), greater<int>());
	int ans = num[0] * 10 + num[1] + num[2];
	cout << ans << endl;
	return 0;
}