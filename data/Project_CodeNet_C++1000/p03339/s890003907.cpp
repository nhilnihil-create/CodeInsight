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

	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		if (!i) {
			for (int j = 1; j < N; j++) {
				if (S.at(j) == 'E') v.at(i)++;
			}
		}
		else {
			int n = v.at(i - 1);
			if (S.at(i) == 'E') n--;
			if (S.at(i - 1) == 'W') n++;
			v.at(i) = n;
		}
	}

	//for (int i = 0; i < N; i++) cout << v.at(i);
	//cout << endl;

	int ans = N;
	for (int i = 0; i < N; i++) {
		ans = min(ans, v.at(i));
	}

	cout << ans << endl;
}