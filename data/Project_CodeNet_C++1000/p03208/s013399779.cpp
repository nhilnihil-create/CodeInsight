#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	vector<int> h(N);
	for (int i = 0; i < N; i++) {
		cin >> h.at(i);
	}
	sort(h.begin(), h.end());

	int h_min = h.at(K - 1) - h.at(0);
	for (int i = 1; i + K - 1 < N; i++) {
		int tmp = h.at(i + K - 1) - h.at(i);
		h_min = min(h_min, tmp);
	}
	cout << h_min << endl;
}