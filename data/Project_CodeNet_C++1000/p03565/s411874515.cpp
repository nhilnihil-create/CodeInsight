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
	reverse(s.begin(), s.end());
	reverse(t.begin(), t.end());
	int n = s.size(), k = t.size();
	bool elf = false;
	rep(i, n) {
		string tmp = s.substr(i, k);
		bool ok = true;
		rep(j, k) if (tmp[j] != '?') if (tmp[j] != t[j]) ok = false;
		if (ok) {
			elf = true;
			for (int j = i; j < i + k; ++j) {
				s[j] = t[j - i];
			}
			break;
		}
	}
	if (!elf) {
		cout << "UNRESTORABLE" << endl;
		return 0;
	}
	rep(i, n) if (s[i] == '?') s[i] = 'a';
	reverse(s.begin(), s.end());
	cout << s << endl;
	return 0;
}
