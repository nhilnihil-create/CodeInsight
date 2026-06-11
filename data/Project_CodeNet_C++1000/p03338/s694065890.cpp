#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int N;
	string S;
	cin >> N >> S;

	int ans = 0;
	for (int i = 1; i < N; i++) {
		string x, y;
		x = S.substr(0, i);
		y = S.substr(i);
		//cout << x << ' ' << y << endl;

		vector<char> v;
		int cnt = 0;
		for (int j = 0; j < x.size(); j++) {
			char ch = x.at(j);
			if ((count(y.begin(), y.end(), ch)) &&
				(count(v.begin(), v.end(), ch) == 0)) {
				cnt++;
				v.push_back(ch);
			}
		}

		ans = max(ans, cnt);
	}

	cout << ans << endl;
}