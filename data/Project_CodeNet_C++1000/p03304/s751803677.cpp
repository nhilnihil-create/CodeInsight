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
	int n, m, d;
	cin >> n >> m >> d;
	cout << fixed << setprecision(8);

	if (d == 0)cout << (double)(m - 1) / n << endl;
	else cout << (double)2 * (n - d) * (m - 1) / n / n;

}