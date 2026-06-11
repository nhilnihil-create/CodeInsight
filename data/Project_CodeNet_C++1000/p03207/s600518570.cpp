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
	vector<int> p(N);
	int sum = 0;
	int ex = 0;
	for (int i = 0; i < N; i++) {
		int p;
		cin >> p;
		sum += p;
		ex = max(ex, p);
	}
	sum -= ex / 2;
	cout << sum << endl;
	return 0;
}