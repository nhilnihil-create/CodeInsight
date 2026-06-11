#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	string s;
	int K;
	cin >> s >> K;

	vector<string> v;

	for (int i = 0; i < s.size(); i++) {
		for (int j = 1; i + j <= s.size(); j++) {
			if (j > K) break;
			string a = s.substr(i, j);
			v.push_back(a);
		}
	}

	sort(v.begin(), v.end());
	unique(v.begin(), v.end());

	cout << v.at(K - 1) << endl;
}