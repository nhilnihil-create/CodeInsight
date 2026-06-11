#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll INF = 1LL<<60;
//int INF = numeric_limits<int>::max();

int main(int, char**) {
	map<char, int> dics;
	map<char, int> dict;
	string s, t;
	cin >> s >> t;
	int n = s.size();
	int cnt1 = 1;
	int cnt2 = 1;
	for (int i=0; i<n; i++) {
		char c1 = s[i];
		int now1;
		if (dics.count(c1)) {
			now1 = dics[c1];
		} else {
			dics[c1] = cnt1;
			now1 = cnt1;
			cnt1++;
		}
		char c2 = t[i];
		int now2;
		if (dict.count(c2)) {
			now2 = dict[c2];
		} else {
			dict[c2] = cnt2;
			now2 = cnt2;
			cnt2++;
		}
		if (now1!=now2) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}