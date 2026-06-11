#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
const int INF = 1e9;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
#define PI 3.14159265358979323846264338327950L
#define MOD 1000000007
//setprecision(15)

int main() {
	int N; cin >> N;
	vector<int> v(N);
	rep(i, N) {
		int tmp; cin >> tmp; tmp *= -1;
		v[i] = tmp;
	}
	sort(v.begin(), v.end());
	int ans = 0;
	int cnt = 0;
	for (auto it = v.begin(); it != v.end(); it++) {
		if (cnt % 2 == 0) {
			ans += -(*it); cnt++;
		} else {
			ans -= -(*it); cnt++;
		}
	}
	cout << ans << endl;
}