#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int N;
	cin >> N;

	vector<string> s(N);
	for (int i = 0; i < N; i++) cin >> s.at(i);

	int M;
	cin >> M;

	vector<string> t(M);
	for (int i = 0; i < M; i++) cin >> t.at(i);

	int ans = 0;
	for (int i = 0; i < N; i++) {
		int n = count(s.begin(), s.end(), s.at(i));
		int m= count(t.begin(), t.end(), s.at(i));
		ans = max(ans, n - m);
	}

	cout << ans << endl;
}