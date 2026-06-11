#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> L(N);
	int longest_L = 0;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> L[i];
		sum += L[i];
		longest_L = max(longest_L, L[i]);
	}
	if (2 * longest_L < sum) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}