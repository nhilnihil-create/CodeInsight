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
	vector<pair<string, int>> restaurant(N);
	for (int i = 0; i < N; i++) {
		cin >> restaurant[i].first >> restaurant[i].second;
		restaurant[i].second *= -1;
	}
	vector<pair<string, int>> T = restaurant;
	sort(T.begin(), T.end());
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (T[i] == restaurant[j]) cout << j + 1 << endl;
		}
	}

	return 0;
}