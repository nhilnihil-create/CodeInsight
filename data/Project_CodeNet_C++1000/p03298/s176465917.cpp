#include<map>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#define REP(i,x,y) for(ll i=x;i<=y;i++)
typedef long long ll;
using namespace std;
struct str {
	string s1; string s2;
	bool operator<(const str& rhs) const {
		if (s1 != rhs.s1) {
			return  s1 > rhs.s1;
		}
		else {
			return s2 > rhs.s2;
		}
	}
};
ll n;
string s;
string t;
map<str, ll> mp;
int main() {
	cin >> n >> s;
	t = s;
	REP(i, 0, n - 1) {
		t[i] = s[n*2 - 1 - i];
	}
	ll p = (1 << n);
	REP(i, 0, p - 1) {
		string t1, t2;
		t1 = t2 = "111111111111111111";
		ll cnt1, cnt2;
		cnt1 = cnt2 = 0;
		REP(j, 0, n - 1) {
			if ((i >> j) & 1 == 1) {
				t1[cnt1] = s[j];
				cnt1++;
			}
			else {
				t2[cnt2] = s[j];
				cnt2++;
			}
		}
		t1 = t1.substr(0, cnt1);
		t2 = t2.substr(0, cnt2);
		//cout << t1<< " " << t2 << endl;
		str k = { t1,t2 };
		//cout << mp[k] << endl;
		mp[k]++;
	}
	ll ans = 0;
	REP(i, 0, p - 1) {
		string t1, t2;
		t1 = t2 = "111111111111111111";
		ll cnt1, cnt2;
		cnt1 = cnt2 = 0;
		REP(j, 0, n - 1) {
			if ((i >> j) & 1 == 1) {
				t1[cnt1] = t[j];
				cnt1++;
			}
			else {
				t2[cnt2] = t[j];
				cnt2++;
			}
		}
		t1 = t1.substr(0, cnt1);
		t2 = t2.substr(0, cnt2);

		str k = { t1,t2 };
		//cout << t1 << " "<<t2 << " " << mp[k] << endl;
		ans += mp[k];
	}
	cout << ans << endl;

}