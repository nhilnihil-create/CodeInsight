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
	if (n == 0) {
		cout << 0 << endl;
		return;
	}
	string s = "";
	while (n != 0) {
		if (n > 0) {
			s += ('0' + (n % 2));
			n = n / 2 * (-1);
		} else {
			if (abs(n) % 2 == 0) {
				n = abs(n) / 2;
				s += '0';
			} else {
				n = abs(n) / 2 + 1;
				s += '1';
			}
		}
	}
	reverse(ALL(s));
	cout << s << endl;
}

int main() {
	solve();
	return 0;
}