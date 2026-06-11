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
	ll n,mcnt=0;
	ll a,sum;
	cin >> n;
	vector<ll>arr;
	rep(i, n) {
		cin >> a;
		if (a < 0)mcnt++;
		arr.push_back(abs(a));
	}
	sort(all(arr));
	sum = accumulate(all(arr), 0LL);
	if (mcnt % 2 == 0) {
		cout << sum << endl;
	}
	else {
		sum -= (arr[0] * 2LL);
		cout << sum << endl;
	}
	return 0;
}

