#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using p = pair<ll, ll>;
using V = vector<int>;
using VV = vector<vector<int>>;
using VVV = vector<vector<vector<int>>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VVVL = vector<vector<vector<ll>>>;
using Graph = VV;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
int Inf = (1 << 30);
ll inf = (1LL << 60);
const int MOD = 1e9 + 7;
int main() {
	int n;
	cin >> n;
	int i;
	V a(n + 2);
	for (i = 1; i <= n; i++) {
		cin >> a[i];
	}
	a[0] = 0;
	a[n + 1] = 0;
	int distance = 0;
	for (i = 0; i <= n; i++) {
		distance += abs(a[i] - a[i + 1]);
	}
	for (i = 1; i <= n; i++) {
		cout << distance - abs(a[i - 1] - a[i]) - abs(a[i] - a[i + 1]) + abs(a[i - 1] - a[i + 1]) << endl;
	}
	return 0;
}