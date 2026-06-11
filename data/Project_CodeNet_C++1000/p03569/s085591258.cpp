#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll INF = 1LL<<60;
//int INF = numeric_limits<int>::max();

int main(int, char**) {
	string s; cin >> s;
	deque<char> S;
	for (int i=0; i<s.size(); i++) S.push_back(s[i]);

	int ret = 0;
	while (!(S.empty() || S.size()==1)) {
		char f = S.front();
		char b = S.back();
		if (f==b) {
			S.pop_front();
			S.pop_back();
		} else if (f=='x') {
			S.pop_front();
			ret++;
		} else if (b=='x') {
			S.pop_back();
			ret++;
		} else {
			cout << -1 << endl;
			return 0;
		}
	}
	cout << ret << endl;

	return 0;
}