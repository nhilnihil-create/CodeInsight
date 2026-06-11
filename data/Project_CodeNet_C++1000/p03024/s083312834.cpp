#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(a) (a).begin(),(a).end()
#define SORT(a) sort(all(a))
#define rSORT(a, i) sort(all(a),(i))

using ll = long long;
constexpr ll INF = 10000000000;
constexpr ll MOD = 1000000007;
constexpr int MAX = 2000200;

using namespace std;

int main() {
	string s; cin >> s;

	int cnt = 0;
	rep(i, s.size()) {
		if (s[i] == 'x') {
			cnt++;
		}
	}
	if (cnt > 7) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
	}
}


