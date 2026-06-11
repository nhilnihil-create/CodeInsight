#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
	int n,k;
	cin >> n >> k;
	if (k == 1) {
		if (1 <= n)cout << "YES" << endl;
		else cout << "NO" << endl;
		return 0;
	}
	n--; k--;
	if (2 <= n / k){
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}

