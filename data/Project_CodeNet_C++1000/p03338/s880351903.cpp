#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <map>
#include <set>
using namespace std;
using ll = long long;

int main(void) {
	int N;
	string S;
	cin >> N >> S;
	map<char, int> X, Y;
	for (int i = 0; i < N; i++) {
		auto it = Y.find(S.at(i));
		if (it != Y.end()) {
			(it->second)++;
		} else {
			Y.emplace(S.at(i), 1);
		}
	}

	int max_intersection = 0;
	for (int i = 0; i < N - 1; i++) {
		// move cut position
		char c = S.at(i);
		if (--(Y.at(c)) == 0) {
			Y.erase(c);
		}
		auto it = X.find(c);
		if (it != X.end()) {
			(it->second)++;
		} else {
			X.emplace(c, 1);
		}
		// calculate intersection size
		int intersection_size = 0;
		for (auto x : X) {
			if (Y.find(x.first) != Y.end()) {
				intersection_size++;
			}
		}
		max_intersection = max(max_intersection, intersection_size);
	}

	cout << max_intersection << endl;
	return 0;
}
