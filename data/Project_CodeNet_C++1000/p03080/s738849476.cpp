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
	int n; cin >> n;
	string s; cin >> s;

	int a = 0;
	int b = 0;

	rep(i, n) {
		if (s[i] == 'R')a++;
		if (s[i] == 'B')b++;
	}
	if (a > b) {
		cout << "Yes" << endl;
		return 0;
	}
	cout << "No" << endl;
}


