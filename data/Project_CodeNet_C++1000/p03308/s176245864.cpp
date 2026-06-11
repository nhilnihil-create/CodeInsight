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
	int n;
	cin >> n;
	vector<int>arr(n);
	rep(i, n)cin >> arr[i];
	sort(all(arr));
	cout << arr[n - 1] - arr[0] << endl;
	return 0;
}

