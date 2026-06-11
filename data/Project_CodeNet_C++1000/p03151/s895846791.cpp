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
	ll n,vsum=0LL,cnt=0,tmp=0,msum=0;
	bool ans = true;
	cin >> n;
	vector<ll>arr(n), brr(n),vdiff(n);
	rep(i, n) cin >> arr[i];
	rep(i, n) {
		cin >> brr[i];
		if (arr[i] < brr[i])ans = false;
		vdiff[i] = arr[i] - brr[i];
	}
	if (ans) { cout << 0 << endl; return 0; }
	vsum = accumulate(all(vdiff), 0LL);
	if (vsum < 0) {
		cout << -1 << endl;
		return 0;
	}
	sort(rall(vdiff));
	for (int i = n - 1; i >= 0;i--) {
		if (0 <= vdiff[i])break;
		msum += vdiff[i];
		cnt++;
	}

	rep(i, n) {
		if (vdiff[i] <= 0) {
			cout << -1 << endl;
			return 0;
		}
		msum += vdiff[i];
		cnt++;
		if (0 <= msum)break;
	}

	cout << cnt << endl;
	return 0;
}

