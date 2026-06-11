#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	string S, T;
	cin >> S >> T;

	sort(S.begin(), S.end());
	sort(T.begin(), T.end());

	vector<int> s(26), t(26);
	for (int i = 0; i < S.size();i++) {
		char ch = S.at(i);
		int n = (int)ch - 97;
		s.at(n)++;
	}
	for (int i = 0; i < T.size(); i++) {
		char ch = T.at(i);
		int n = (int)ch - 97;
		t.at(n)++;
	}

	sort(s.begin(), s.end());
	sort(t.begin(), t.end());

	if (s == t) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}