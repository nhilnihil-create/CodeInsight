#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
#define rep(i, j, n) for(int i = (j); i < (n); ++i)
#define rrep(i, j, n) for(int i = (n) - 1; (j) <= i; --i)
constexpr ll MOD = 1000000007;
constexpr ll INF = 1LL << 60;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);
	string s; cin >> s;
	int n = s.size();
	rep(i, 0, n + 1) {
		rep(j, i, n + 1) {
			string t = s;
			if (t.erase(i, j - i + 1) == "keyence") {
				cout << "YES" << endl;
				return 0;
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}
