//IOI 2021
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second

typedef long long ll;
typedef pair<int, int> pii;

ll a, b, c, k, ans;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> a >> b >> c >> k;
	if (k & 1)
		ans = - a + b;
	else
		ans = a - b;
	cout << ans << endl;
	return 0;
}
