#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

const int Q = 100001;
vector<int> isPrime, is;
vector<int> sumP;

void init() {
	isPrime.resize(Q);
	for (int i = 2; i < Q; i++) {
		int n = i;
		bool b = true;
		for (int j = 2; j * j <= n; j++) {
			if (n % j == 0) {
				b = false;
				break;
			}
		}
		if (b) {
			isPrime[i]++;
		}
	}
	is.resize(Q);
	rep(i,Q) {
		if (i % 2 == 0) continue;
		if (isPrime[i] && isPrime[(i + 1) / 2]) is[i]++;
	}
	sumP.resize(Q);
	for (int i = 1; i < Q; i++) {
		sumP[i] = sumP[i - 1] + is[i];
	}
}

void solve() {
	int q;
	cin >> q;
	vector<int> l(q), r(q);
	rep(i,q) {
		cin >> l[i] >> r[i];
	}
	rep(i,q) {
		cout << sumP[r[i]] - sumP[l[i] - 1] << endl;
	}
}

int main() {
	init();
	solve();
	return 0;
}