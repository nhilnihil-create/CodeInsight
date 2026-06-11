#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;
using pint = pair<int, int>;

bool cmp(const pair<int, pair<string, int>>& a, const pair<int, pair<string, int>>& b) {

	bool ret = false;
	if (a.second.first < b.second.first) {
		ret = true;
	}
	else if (a.second.first == b.second.first){
		if (a.second.second > b.second.second) {
			ret = true;
		}
	}
	return ret;
}

int main() {
	int N;
	cin >> N;
	vector<pair<int, pair<string, int>>> a;

	for (int i = 0; i < N; ++i) {
		string S;
		int P;
		cin >> S >> P;
		pair<int, pair<string, int>> tmp(i, make_pair(S, P));
		a.push_back(tmp);
	}

	sort(a.begin(), a.end(), cmp);

	for (auto aa : a) {
		cout << aa.first + 1 << endl;
	}

	return 0;
}
