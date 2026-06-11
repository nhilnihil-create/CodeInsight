#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>

using namespace std;

int main() {
	int N, T, A;
	cin >> N >> T >> A;
	vector<pair<double, int>> imfo(N);
	for (int i = 0; i < N; i++) {
		int H;
		cin >> H;
		double temperature = abs(T - H * 0.006 - A);
		imfo[i].first = temperature;
		imfo[i].second = i + 1;

	}
	sort(imfo.begin(), imfo.end());
	cout << imfo[0].second << endl;
	return 0;
}