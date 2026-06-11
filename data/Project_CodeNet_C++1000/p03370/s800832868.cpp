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
	int n,x;
	cin >> n >> x;
	vector<int>snack(n);

	rep(i, n)cin >> snack[i];
	int zairyo = x - accumulate(all(snack),0);
	sort(all(snack));
	cout << n + zairyo / snack[0] << endl;
	return 0;
}

