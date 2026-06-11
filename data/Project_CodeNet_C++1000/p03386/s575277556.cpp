#include "bits/stdc++.h"
using namespace std;

int main() {
	int A, B, K;
	cin >> A >> B >> K;
	vector<int>Set;
	for (int i = 0; i < K; ++i) {
		if (A + i <= B) {
			Set.push_back(A + i);
		}
	}
	for (int i = 0; i < K; ++i) {
		if (A <= B - i) {
			Set.push_back(B - i);
		}
	}
	sort(Set.begin(), Set.end());
	Set.erase(std::unique(Set.begin(), Set.end()), Set.end());
	for (int i = 0; i < Set.size(); ++i) {
		cout << Set[i] << endl;
	}
	return 0;
}
