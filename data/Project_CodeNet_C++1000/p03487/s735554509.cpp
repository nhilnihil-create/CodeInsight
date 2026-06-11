#include "bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;
const int INF = 1 << 30;
const long long LINF = 1LL << 60;
const long long MOD = 1000000000 + 7;
const double PI = acos(-1);

int main() {
	int N; cin >> N;
	vector<int> a(N);
	map<int, int>mp;
	rep(i, N) {
		cin >> a[i];
		++mp[a[i]];
	}
	int ans = 0;
	for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
		int key = itr->first;
		int num = itr->second;
		if (key <= num) {
			ans += (num - key);
		}
		else {
			ans += num;
		}
	}
	cout << ans;
}

