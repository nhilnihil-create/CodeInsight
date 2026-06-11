
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int v[100000];

int main() {
	int n;
	cin >> n;

	for (int i=0; i<n; i++) {
		cin >> v[i];
	}

	map<int, int> e_cnt, o_cnt;

	int even_n = 0;
	for (int i=0; i<n; i+=2) {
		e_cnt[v[i]]++;
		even_n++;
	}

	int odd_n = 0;
	for (int i=1; i<n; i+=2) {
		o_cnt[v[i]]++;
		odd_n++;
	}

	int e_most_num = -1;
	int e_most_cnt = 0;
	int e_2nd_most_num = -1;
	int e_2nd_most_cnt = 0;
	for (auto itr : e_cnt) {
		int num = itr.first;
		int val = itr.second;
		if (val > e_most_cnt) {
			e_2nd_most_num = e_most_num;
			e_2nd_most_cnt = e_most_cnt;
			e_most_num = num;
			e_most_cnt = val;
		} else if (val > e_2nd_most_cnt) {
			e_2nd_most_num = num;
			e_2nd_most_cnt = val;
		}
	}

	// **** debug ****
	//cout << "e_most_num=" << e_most_num << " e_2nd_most_num=" << e_2nd_most_num << endl;
	//cout << "e_most_cnt=" << e_most_cnt << " e_2nd_most_cnt=" << e_2nd_most_cnt << endl;

	int o_most_num = -1;
	int o_most_cnt = 0;
	int o_2nd_most_num = -1;
	int o_2nd_most_cnt = 0;
	for (auto itr : o_cnt) {
		int num = itr.first;
		int val = itr.second;
		if (val > o_most_cnt) {
			o_2nd_most_num = o_most_num;
			o_2nd_most_cnt = o_most_cnt;
			o_most_num = num;
			o_most_cnt = val;
		} else if (val > o_2nd_most_cnt) {
			o_2nd_most_num = num;
			o_2nd_most_cnt = val;
		}
	}

	// **** debug ****
	//cout << "o_most_num=" << o_most_num << " o_2nd_most_num=" << o_2nd_most_num << endl;
	//cout << "o_most_cnt=" << o_most_cnt << " o_2nd_most_cnt=" << o_2nd_most_cnt << endl;

	int ans = INF;

	// even の most_num を採用する場合
	int ans_candidate = even_n - e_most_cnt;

	if (e_most_num == o_most_num) {
		ans_candidate += odd_n - o_2nd_most_cnt;
	} else {
		ans_candidate += odd_n - o_most_cnt;
	}

	ans = min(ans, ans_candidate);

	// odd の most_num を採用する場合
	ans_candidate = odd_n - o_most_cnt;

	if (o_most_num == e_most_num) {
		ans_candidate += even_n - e_2nd_most_cnt;
	} else {
		ans_candidate += even_n - e_most_cnt;
	}

	ans = min(ans, ans_candidate);

	cout << ans << endl;

	return 0;
}