#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
using ll=long long;
using pll=pair<ll,ll>;

#define fi first
#define se second
#define pb push_back
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define MOD 1000000007

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
	string s,t;
	cin >> s >> t;
	map<char, int> mps,mpt;
	rep(i, s.length()) mps[s[i]]++;
	rep(i, t.length()) mpt[t[i]]++;
	string ans = "No";
	sort(s.begin(), s.end());
	sort(t.begin(), t.end(), greater<char>());
	//cout << s << endl << t << endl;

	if(s < t) cout << "Yes" << endl;
	else cout << "No" << endl;
	/*rep(i, max(s.length(), t.length())) {
		if(i == s.length()) {
			cout << "Yes" << endl;
			return 0;
		}
		if(i == t.length()) {
			cout << "No" << endl;
			return 0;
		}
		if(s[i] < t[i]) {
			cout << "Yes" << endl;
			return 0;
		}
		if(s[i] > t[i]) {
			cout << "No" << endl;
			return 0;
		}
	}*/

  return 0;
}
