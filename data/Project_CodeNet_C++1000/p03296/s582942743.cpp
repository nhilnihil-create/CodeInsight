//IOI 2021
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 100 + 17;

int n, a[MAXN], ans;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		cnt++;
		if (a[i] != a[i + 1])
			ans += cnt / 2, cnt = 0;
	}
	cout << ans << endl;
	return 0;
}
