#include "bits/stdc++.h"
using namespace std;

int main() {
	string S;
	int K;
	cin >> S >> K;
	vector<string>Set;
	for (int i = 1; i <= K; ++i) {
		for (int j = 0; j < S.size(); ++j) {
			Set.push_back(S.substr(j, i));
		}
	}
	sort(Set.begin(), Set.end());
	std::unique(Set.begin(), Set.end());
	cout << Set[K - 1] << endl;
	return 0;
}
