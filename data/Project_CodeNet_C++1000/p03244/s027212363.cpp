#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main() {

	int n; cin >> n;

	const int p = 100001;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
		
	vector<int> a(p, 0), b(p, 0);
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			a[v[i]]++;
		}
		else {
			b[v[i]]++;
		}
	}

	int a_max_cnt = 0;
	int b_max_cnt = 0;
	int a_second_max_cnt = 0;
	int b_second_max_cnt = 0;
	int a_max_cnt_num;
	int b_max_cnt_num;
	for (int i = 0; i < p; i++) {
		if (a_max_cnt <= a[i]) {
			a_second_max_cnt = a_max_cnt;
			a_max_cnt = a[i];
			a_max_cnt_num = i;
		}
		else if (a_second_max_cnt <= a[i]) {
			a_second_max_cnt = a[i];
		}

		if (b_max_cnt <= b[i]) {
			b_second_max_cnt = b_max_cnt;
			b_max_cnt = b[i];
			b_max_cnt_num = i;
		}
		else if (b_second_max_cnt <= b[i]) {
			b_second_max_cnt = b[i];
		}
	}

	if (a_max_cnt_num == b_max_cnt_num) {
		cout << min(n - a_second_max_cnt - b_max_cnt, n - a_max_cnt - b_second_max_cnt);
	}
	else {
		cout << n - a_max_cnt - b_max_cnt << endl;
	}

	return 0;
}