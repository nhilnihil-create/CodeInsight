// :)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define F first
#define S second
#define MP make_pair

const int MAX = 1e5+9;
const ll MOD = 1e9+7;

ll x[MAX], v[MAX];
ll d1[MAX], d2[MAX];

int main () {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; ll c;
	cin >> n >> c;
	for (int i = 0; i < n; i++)
		cin >> x[i] >> v[i];
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		sum += v[i];
		if (i == 0)
			d1[i] = max(sum - x[i], (ll)0);
		else
			d1[i] = max(d1[i-1], sum - x[i]);
	}
	sum = 0;
	for (int i = n-1; i >= 0; i--) {
		sum += v[i];
		if (i == n-1)
			d2[i] = max(sum - (c-x[i]), (ll)0);
		else
			d2[i] = max(d2[i+1], sum - (c-x[i]));
	}
	ll res = 0;
	sum = 0;
	for (int i = 0; i < n; i++) {
		sum += v[i];
		res = max(res, sum - 2*x[i] + d2[i+1]);
		res = max(res, sum - x[i]);
	}
	sum = 0;
	for (int i = n-1; i >= 0; i--) {
		sum += v[i];
		res = max(res, sum - 2*(c-x[i]) + ((i) ? d1[i-1] : 0));
		res = max(res, sum - (c-x[i]));
	}
	cout << res << "\n";
}