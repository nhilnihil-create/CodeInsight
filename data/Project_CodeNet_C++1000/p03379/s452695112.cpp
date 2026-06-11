/*"for if God is with them who can be against them."
   it's beter to die struggling than to abandon the effort where there is still
   a chance of accomlishing something more..NEVER GIVE UP.
   */

/* "IF THERE IS NO WAY OUT LOOK AT THE BOTTOM". */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define endl '\n'
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define all(a) a.begin(),a.end()
#define watch(x) cout << (#x) << " is " << (x) << endl
void solve() {
	int n;
	cin >> n;
	int a[n + 1], b[n + 1];
	REP(i, 1, n ) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b + 1, b + n + 1);
	int k = n / 2;
	int x = b[k], y = b[k + 1];
	bool ok = false;
	if (x == y) {
		ok = true;
	}
	if (ok) {
		REP(i, 0, n - 1) {
			cout << x << endl;
		}
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] <= x) {
			cout << y << endl;
		}
		else
			cout << x << endl;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif
	IOS;
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
#ifndef ONLINE_JUDGE
	cout << "\nTime Elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec\n";
#endif
	return 0;
	/*TRY AGAIN, NO MATTER HOW MANY TIMES YOU FAILED ALWAYS TRY ONCE MORE*/
}