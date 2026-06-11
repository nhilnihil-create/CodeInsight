#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	string S;
	cin >> S;

	int c = 0;
	vector<int> v;

	for (int i = 0; i < S.size(); i++) {
		char ch = S[i];
		v.push_back(ch);
		if (v.size() > 1) {
			if (v[v.size() - 1] != v[v.size() - 2]) {
				c += 2;
				v.pop_back();
				v.pop_back();
			}
		}
	}

	cout << c << endl;
}