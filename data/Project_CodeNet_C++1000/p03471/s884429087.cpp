#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define dup(x,y) (((x)+(y)-1)/(y))
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const double EPS = 1e-10;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main() {
	int n, y;
	cin >> n >> y;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			int k = n - i - j;
			if (k < 0) continue;
			if (10000*i + 5000*j + 1000*k == y) {
				cout << i << " " << j << " " << k << endl;
				return 0;
			}
		}
	}
	cout << -1 << " " << -1 << " " << -1 << endl;
}