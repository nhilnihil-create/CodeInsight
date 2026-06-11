#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> P;
constexpr auto INF = INT_MAX/2;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;

int n, m, q;
int lr[505][505];
int lsum[505][505];
int pq[505][505];

int main() {

	cin >> n >> m >> q;

	vi s(q), t(q);

	rep(i, m){
		int l, r;
		cin >> l >> r;
		l--;r--;
		lr[l][r]++;
	}

	rep(i, q)cin >> s[i] >> t[i];

	rep(i, n)lsum[i][i] = lr[i][i];
	rep(i, n)rep1(j, n-1)lsum[i][j] = lsum[i][j - 1] + lr[i][j];

	rep(i, n)rep(j, n)rep(k, j - i + 1)pq[i][j] += lsum[i + k][j];

	rep(i, q)cout << pq[s[i] - 1][t[i] - 1] << endl;

}