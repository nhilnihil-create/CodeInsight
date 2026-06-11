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
	string s;
	cin >> s;
	rep(i,(1 << 3)) {
		int x = s[0] - '0';
		rep(j,3) {
			if (i & (1 << j)) {
				x += s[j+1] - '0';
			} else {
				x -= s[j+1] - '0';
			}
		}
		if (x == 7) {
			char op[3];
			rep(j,3) {
				op[j] = ((i & (1 << j))? '+': '-'); 
			}
			rep(j,3) {
				printf("%c%c", s[j], op[j]);
			}
			printf("%c=7\n", s[3]);
			return;
		}
	}
}

int main() {
	solve();
	return 0;
}