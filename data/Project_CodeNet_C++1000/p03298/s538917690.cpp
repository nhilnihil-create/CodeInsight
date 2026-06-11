#include <bits/stdc++.h>

using namespace std;
using ll =long long;
#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//Write From this Line

int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;

	string s1 = s.substr(0,n);
	string s2 = s.substr(n,n);
	reverse(s2.begin(),s2.end());

	map<pair<string, string>, ll> mp;
	for (int tmp = 0; tmp < (1 << n); tmp++){
		bitset<20> bit(tmp);
		string a = "";
		string b = "";
		rep(i, n) {
			if (bit.test(i)) a +=s1[i];
			else b += s1[i];
		}
		mp[make_pair(a,b)] ++;
	}

	ll ans = 0;
	for (int tmp = 0; tmp < (1 << n); tmp++){
		bitset<20> bit(tmp);
		string a = "";
		string b = "";
		rep(i, n) {
			if (bit.test(i)) a +=s2[i];
			else b += s2[i];
		}
		ans += mp[make_pair(a,b)];
	}
	cout << ans << endl;
}
