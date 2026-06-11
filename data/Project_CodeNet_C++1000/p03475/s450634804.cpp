#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void solve() {
	int n;
	cin >> n;
	vector<ll> c(n-1), s(n-1), f(n-1);
	rep(i,n-1) cin >> c[i] >> s[i] >> f[i];
	rep(i,n) {
		ll time = 0;
		for (int j = i; j < n-1; j++) {
			if (time < s[j]) time = s[j];
			if (time % f[j] != 0) time += f[j] - time % f[j];
			time += c[j];
		}
		cout << time << endl;
	}
}

int main() {
	solve();
	return 0;
}