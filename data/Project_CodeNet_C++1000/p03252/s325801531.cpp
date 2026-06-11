#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define maxs(a, b) a = max(a, b)
#define mins(a, b) a = min(a, b)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll linf = (1ll << 61);
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s, t;
	cin >> s >> t;
	sort(all(s));
	sort(all(t));
	vector<int> cnt1(26), cnt2(26);
	int n = s.size();
	rep(i, n) {
		cnt1[s[i] - 'a']++;
		cnt2[t[i] - 'a']++;
	}
	sort(all(cnt1));
	sort(all(cnt2));
	if (cnt1 == cnt2) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}