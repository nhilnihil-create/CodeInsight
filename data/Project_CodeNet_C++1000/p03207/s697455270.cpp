#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
const int MOD = (int)1e9 + 7;
const int INF = (int)1e9 * 2;

int main() {
	int n;
	cin >> n;
	vector<int> p(n);
	rep(i, n) cin >> p[i];
	sort(p.begin(), p.end());
	int out = p[n - 1] / 2;
	rep(i, n - 1) out += p[i];
	cout << out << endl;
}
