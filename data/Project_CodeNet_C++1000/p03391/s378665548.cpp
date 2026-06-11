#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> pi;
#define f first
#define s second
#define FAST ios_base::sync_with_stdio(0); cin.tie(0);
const int maxn = 200010;

int n;
int total;
bool notequal;

int32_t main() {
	cin >> n;
	int ans = INT_MAX/2;
	for (int i =0;i<n;i++) {
		int a,b; cin >> a >> b;
		total += a;
		if (a > b) ans = min(ans,b);
		if (a != b) notequal = true;
	}
	if (!notequal) cout << 0;
	else cout << total - ans;
}

