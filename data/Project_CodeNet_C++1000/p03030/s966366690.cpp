#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

bool compare_P(pair<string, int> a, pair<string, int> b) {
	if (a.first == b.first) {
		return a.second > b.second;
	}
	else {
		return a.first < b.first;
	}
}

int main() {
	int N; cin >> N;
	vector<pair<string, int>> p1(N);
	vector<pair<string, int>> p2(N);
	for (int i = 0; i < N; i++) {
		string S; int P; cin >> S >> P;
		p1.at(i) = make_pair(S, P);
		p2.at(i) = make_pair(S, P);
	}

	sort(p1.begin(), p1.end(), compare_P);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (p1[i].first == p2[j].first && p1[i].second == p2[j].second) {
				cout << j + 1 << endl;
			}
		}
	}
}