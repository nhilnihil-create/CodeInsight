#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n;
	vector<ll> d(n);
	map<ll, int> mp;
	rep(i, n) {
		cin >> d[i];
		mp[d[i]]++;
	}
	sort(all(d));
	cin >> m;
	vector<ll> t(m);
	rep(i, m) cin >> t[i];
	bool elf = true;
	rep(i, m) {
		if (mp[t[i]] == 0) elf = false;
		else {
			mp[t[i]]--;
		}
	}
	cout << (elf ? "YES" : "NO") << endl;
	return 0;
}
