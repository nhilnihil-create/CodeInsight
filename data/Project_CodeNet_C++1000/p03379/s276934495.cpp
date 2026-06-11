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
	vector<int>arr(n),sortarr;
	rep(i, n)cin >> arr[i];
	sortarr = arr;
	sort(all(sortarr));
	int mid = n / 2;
	int one = sortarr[mid - 1], two = sortarr[mid];

	rep(i, n) {
		if (arr[i] <= one)cout << two << endl;
		else cout << one << endl;
	}
	return 0;
}

