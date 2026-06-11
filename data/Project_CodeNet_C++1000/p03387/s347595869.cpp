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
	int a, b, c;
	cin >> a >> b >> c;
	int s = a + b + c;
	int mx = max(a,max(b, c));
	if (s % 2 == mx % 2) {
		cout << (mx * 3 - s) / 2 << endl;
	} else {
		cout << ((mx + 1) * 3 - s) / 2 << endl;
	}
}

int main() {
	solve();
	return 0;
}