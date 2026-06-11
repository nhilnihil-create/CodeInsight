
// C - K-th Substring

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	string s;
	cin >> s;

	int K;
	cin >> K;

	set<string> substr_list;
	for (int i=0; i<s.size(); i++) {
		for (int j=i; j<s.size(); j++) {
			if (j-i > 5) continue;
			substr_list.insert(s.substr(i, j-i+1));
		}
	}

	auto itr = substr_list.begin();
	for (int i=1; i<K; i++) {
		itr++;
	}

	string ans = *itr;

	cout << ans << endl;

	return 0;
}