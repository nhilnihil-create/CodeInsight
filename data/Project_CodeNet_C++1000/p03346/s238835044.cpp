#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define all(x) (x).begin(), (x).end()
#define fap(x) cerr << __LINE__ << " says: " << #x << " = " << (x) << "\n"
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int inf = 0x3f3f3f3f;
const ll INF = 2e18;

int main() {
	FastIO;

	int n;
	cin >> n;

	vector<int> a(n), pos(n);
	for(int i=0; i<n; ++i) {
		cin >> a[i];
		--a[i];
		pos[a[i]] = i;
	}

	int res = n - 1, pre = 1;
	for(int i=n-2; i>=0; --i) {
		int len = 1;
		if(pos[i] < pos[i+1]) len += pre;
		res = min(res, n - len);
		pre = len;
	}
	cout << res << "\n";

	return 0;
}