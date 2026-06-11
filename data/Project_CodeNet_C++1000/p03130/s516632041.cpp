#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(a) (a).begin(),(a).end()
#define SORT(a) sort(all(a))
#define rSORT(a, i) sort(all(a),(i))

using ll = long long;
constexpr ll INF = 10000000000;
constexpr ll MOD = 1000000007;
constexpr int MAX = 2000200;
constexpr double EPS = 1E-11;

using namespace std;

int main() {
	vector<int>a(3);
	rep(i, 3)cin >> a[i];
	vector<int>b(3);
	rep(i, 3)cin >> b[i];

	vector<int>res(4);
	for (int i = 0; i < 3; i++) {
		res[a[i] - 1]++;
		res[b[i] - 1]++;
	}
	rep(i, 4) {
		if (res[i] >= 3) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;

	//rep(i, 4)cout << res[i] << "\n";
}