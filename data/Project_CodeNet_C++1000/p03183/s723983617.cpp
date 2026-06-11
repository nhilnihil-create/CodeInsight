//khodaya khodet komak kon
#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define all(x) x.begin(), x.end()
#pragma GCC optimise ("ofast")
#pragma GCC optimise("unroll-loops")

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 1000 + 10, W = 20010;
const ll MOD = 1000000000 + 7;
const ll INF = 1000000000000000000;
const ll LOG = 25;

int n, a[N], w[N], s[N], v[N], ind[N];
ll dp[N][W], ps[N][W];

bool cmp(int x, int y){
	return w[x] + s[x] < s[y] + w[y];
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> w[i] >> s[i] >> v[i];
		ind[i] = i;
	}
	sort(ind + 1, ind + n + 1, cmp);
	for (int i = 1; i <= n; i++){
		//cout << ind[i] << '\n';
		for (int j = 0; j < w[ind[i]]; j++) dp[i][j] = dp[i - 1][j];
		for (int j = w[ind[i]]; j <= min(W - 1, s[ind[i]] + w[ind[i]]); j++){
			//cout << i << ' ' << j << ' ' << v[ind[i]] << '\n';
			dp[i][j] = max(dp[i - 1][j], ps[i - 1][j - w[ind[i]]] + v[ind[i]]);
		}
		for (int j = min(W - 1, s[ind[i]] + w[ind[i]]) + 1; j < W; j++) dp[i][j] = dp[i - 1][j];
		ps[i][0] = dp[i][0];
		for (int j = 1; j < W; j++) ps[i][j] = max(dp[i][j], ps[i][j - 1]);
	}
	//cout << ps[1][2] << '\n';
	//cout << dp[2][4] << '\n';
	cout << ps[n][W - 1];









	return 0;
}
