#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define dup(x,y) (((x)+(y)-1)/(y))
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const double EPS = 1e-10;
const int INF = 1e9;
const ll LINF = 1e15;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> b(n+1, 0), w(n+1, 0);
	rep(i,n) {
		w[i+1] = w[i] + (s[i] == '.');
		b[i+1] = b[i] + (s[i] == '#');
	}

	int ans = INF;
	for(int i = 0; i < n+1; i++) {
		int lb = b[i] - b[0];
		int rw = w[n] - w[i];
		ans = min(ans, lb + rw);
	}
	cout << ans << endl;
}