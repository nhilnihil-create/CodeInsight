#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int N;
	cin >> N;

	vector<string> v;
	for (int i = 0; i < N; i++) {
		string w;
		cin >> w;
		if (!i) {
			v.push_back(w);
			continue;
		}

		if (count(v.begin(), v.end(), w)) {
			cout << "No" << endl;
			return 0;
		}

		string l = v.back();
		if (l.back()!=w.front()) {
			cout << "No" << endl;
			return 0;
		}

		v.push_back(w);
	}

	cout << "Yes" << endl;
}