#include<iostream>
#include<string>
using namespace std;
#define rep(i,m,n) for(int (i)=(int)(m);i<(int)(n);i++)
#define REP(i,n) rep(i,0,n)
#define FOR(i,c) for(decltype((c).begin())i=(c).begin();i!=(c).end();++i)
#define ll long long

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	ll ans = 0;
	ll cnt = 0;
	REP(i, s.size()) {
		if (s[i] == 'A') {
			cnt++;
			continue;
		}
		if (i!=s.size()-1&&s.substr(i, 2) == "BC") {
			ans += cnt;
			i++;
			continue;
		}
		cnt = 0;
	}
	cout << ans << endl;

	return 0;
}
