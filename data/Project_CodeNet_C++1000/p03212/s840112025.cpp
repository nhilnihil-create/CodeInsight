#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const ll LINF = 1e15;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

ll n;

int dfs(ll cur, int a, int b, int c) {
	if (cur > n) return 0;
	int res = 0;
	if (a == 0 || b == 0 || c == 0) res = 0;
	else res += 1;
	res += dfs(cur * 10 + 7, a+1, b, c);
	res += dfs(cur * 10 + 5, a, b+1, c);
	res += dfs(cur * 10 + 3, a, b, c+1);
	return res;
}

int main() {
	cin >> n;
	cout << dfs(0, 0, 0, 0) << endl;
}