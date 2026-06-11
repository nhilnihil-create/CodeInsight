#include <bits/stdc++.h>
using namespace std;

int main()
{
	string S;
	cin >> S;
	if (S.size() <= 1) {
		puts("YES");
		return 0;
	}
	int cnt[3] = {};
	for (auto c : S) {
		cnt[c - 'a']++;
	}
	sort(cnt, cnt + 3);
	cout << (cnt[2] <= cnt[0] + (S.size() % 3 != 0) ? "YES" : "NO") << endl;
	return 0;
}
