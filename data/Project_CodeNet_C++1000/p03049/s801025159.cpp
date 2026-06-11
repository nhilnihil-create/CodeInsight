
// C - AB Substrings

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	int N;
	cin >> N;

	int cnt_ab = 0;
	int cnt_begin_b = 0;
	int cnt_end_a = 0;
	bool all_begin_b_end_a = true;

	for (int i=0; i<N; i++) {
		string s;
		cin >> s;

		for (int j=0; j<s.size()-1; j++) {
			if (s[j] == 'A' && s[j+1] == 'B') cnt_ab++;
		}

		if (s[0] == 'B') cnt_begin_b++;

		if (s[s.size()-1] == 'A') cnt_end_a++;

		if (s[0] == 'B' && s[s.size()-1] != 'A') all_begin_b_end_a = false;
		if (s[0] != 'B' && s[s.size()-1] == 'A') all_begin_b_end_a = false;
	}

	int ans = cnt_ab + min(cnt_begin_b, cnt_end_a);

	if (cnt_begin_b > 0 && all_begin_b_end_a) ans--;

	cout << ans << endl;

	return 0;
}