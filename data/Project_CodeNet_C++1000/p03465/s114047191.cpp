#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define FF first
#define SS second
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pie;
const int MOD = 1e9 + 7;
const int INF = 2e9;
const ll LINF = 4e18;
const ll delta = 96181;

const int M = 4e6 + 5;
const int N = 2e3 + 20;
bitset<M> B;
vector<int> ans;
int n, S;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	B[0] = 1;
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		B = B | (B << x);
		S += x;
	}
	for (int i = 0; i < M; i++)
		if (B[i])
			ans.push_back(i);
	cout << ans[ans.size() / 2] << endl;
}

