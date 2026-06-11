#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

int main() {

	int N;
	cin >> N;
	vector<int> a;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	vector<string> ope_log;

	// 全てを正または負にするための数値のindexを取得
	int max_idx = distance(a.begin(), max_element(a.begin(), a.end()));
	int min_idx = distance(a.begin(), min_element(a.begin(), a.end()));
	int fix_idx, all_positive;
	if (abs(a[max_idx]) < abs(a[min_idx])) {
		fix_idx = min_idx;
		all_positive = false;
	}
	else {
		fix_idx = max_idx;
		all_positive = true;
	}
	// 全ての数にfix_idxの値を足す
	for (int i = 0; i < N; i++) {
		if (i != fix_idx) {
			a[i] += a[fix_idx];
			ope_log.push_back(to_string(fix_idx+1) + " " + to_string(i+1));
		}
	}
	// 累積和を取っていく
	if (all_positive) {
		for (int i = 1; i < N; i++) {
			a[i] += a[i - 1];
			ope_log.push_back(to_string(i) + " " + to_string(i+1));
		}
	}
	else {
		for (int i = N-2; i >= 0; i--) {
			a[i] += a[i+1];
			ope_log.push_back(to_string(i+2) + " " + to_string(i+1));
		}
	}
	// 答えの出力
	cout << ope_log.size() << endl;
	for (vector<string>::iterator it = ope_log.begin(); it != ope_log.end(); it++)
		cout << *it << endl;

	return 0;
}