#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll MOD = (1e+9)+7;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-11;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
typedef pair<ll,P> PP;
int main() {
	string s; cin >> s;
	int x, y; cin >> x >> y;
	int len = s.length();
	bool f = true;
	vector<int> odd, even;
	int sta = 0;
	rep(i, len) {
		if (s[i] == 'F') {
			int chk = i;
			while (i + 1 < len&&s[i + 1] == 'F')i++;
			if (chk == 0) {
				sta= i - chk + 1; continue;
			}
			if (f)odd.push_back(i - chk + 1);
			else even.push_back(i - chk + 1);
		}
		else f = !f;
	}
	bitset<24001> exi1, exi2;
	exi1[8000+sta] = exi2[8000] = 1;
	int len1 = odd.size();
	int len2 = even.size();
	rep(i, len1) {
		exi1 = (exi1 << odd[i]) | (exi1 >> odd[i]);
	}
	rep(i, len2) {
		exi2 = (exi2 << even[i]) | (exi2 >> even[i]);
	}
	if (exi1[x + 8000] && exi2[y + 8000])cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}