#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define E "\n"

using namespace std;
const long long MOD = (long long)1e9 + 7;

int N, n, a[1000009];
multiset<int> s[1000009];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	n = 1 << N;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s[i].insert(a[i]);
	}
	for (int i = 0; i < N; i++) {
		int cur = 1 << i;
		for (int j = 0; j < n; j++) {
			if ((cur & j) == 0) {
				for (auto x : s[j]) {
					s[cur | j].insert(x);
				}
				while (s[cur | j].size() > 2) {
					auto x = s[cur | j].begin();
					s[cur | j].erase(x);
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i < n; i++) {
		auto x = s[i].begin();
		int tmp = *x;
		x++;
		tmp += *x;
		ans = max(tmp, ans);
		cout << ans << E;
	}
	//system("pause");
	return 0;
}