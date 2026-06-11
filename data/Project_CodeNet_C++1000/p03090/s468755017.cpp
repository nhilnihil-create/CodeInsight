#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vb> vvb;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()

constexpr auto INF = INT_MAX/2;
constexpr auto MOD = 1000000007;


int main() {

	int n;
	cin >> n;

	int m = n * (n - 1) / 2 - n / 2;
	cout << m << endl;

	vvb path(n, vb(n, true));
	rep(i, n / 2) {
		path[i][(n / 2) * 2 - 1 - i] = false;
		path[(n / 2) * 2 - 1 - i][i] = false;
	}

	rep(i, n)rep(j, n) {
		if (i >= j)continue;
		if (path[i][j])cout << i + 1 << " " << j + 1 << endl;
	}

}