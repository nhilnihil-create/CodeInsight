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
	int n,mid;
	cin >> n;
	mid = n / 2;
	map<int, int>mp;
	vector<int>arr(n),sortarr,tmp;
	rep(i, n) {
		cin >> arr[i];
		mp[arr[i]]++;
	}
	sortarr = arr;
	sort(all(sortarr));
	int one = sortarr[mid - 1], two = sortarr[mid];
	rep(i, n) {
		if (arr[i] <= one)cout << two << endl;
		else cout << one << endl;
	}

	return 0;
}

