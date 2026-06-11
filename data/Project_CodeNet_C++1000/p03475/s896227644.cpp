#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;

#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
constexpr auto INF = 1050000000;
constexpr auto MOD = 1000000007;

int main() {
	int n;
	cin >> n;
	vi c(n-1), s(n-1), f(n-1);
	rep(i, n-1)cin >> c[i] >> s[i] >> f[i];

	rep(i, n) {
		int t = 0;
		rep(j, n - 1 - i) {
			if (t < s[i + j])t = s[i + j];
			else if (t % f[i + j])t += (f[i + j] - (t % f[i + j]));
			t += c[i + j];
		}
		cout << t << endl;
	}
}