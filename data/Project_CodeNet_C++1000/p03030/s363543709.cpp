#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <tuple>

using namespace std;

int main() {
	int N, P;
	string S;
	vector<tuple<string, int, int>> SPs;
	int num;
	
	cin >> N;

	for (int i = 0; i < N;i++) {
		cin >> S >> P;
		SPs.push_back(make_tuple(S, -P, i+1));
	}
	sort(SPs.begin(), SPs.end());

	for (tuple<string, int, int>SP : SPs) {
		tie(ignore, ignore, num) = SP;
		cout << num << "\n";
	}

	return 0;
}