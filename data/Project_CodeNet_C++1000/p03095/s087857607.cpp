#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int N = 1e5 + 5, M = 27, mod = 1e9 + 7;

int cnt[M];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	string s;
	cin >> n >> s;
	int ans = 1;
	fill(cnt, cnt + 26, 1);
	for (auto ch : s)
		cnt[ch - 'a']++;
	for (int i = 0; i < 26; i++)
		ans = (1LL * ans * cnt[i]) % mod;
	cout << (ans - 1 + mod) % mod << "\n";
}
