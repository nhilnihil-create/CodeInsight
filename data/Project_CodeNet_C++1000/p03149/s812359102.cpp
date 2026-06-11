#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define dunk(a) cout << (a) << endl
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<int> n(4);
	rep(i, 4) cin >> n[i];
	sort(all(n));
	vector<int> ans = { 1,4,7,9 };
	if (n == ans) puts("YES");
	else puts("NO");
	return 0;
}