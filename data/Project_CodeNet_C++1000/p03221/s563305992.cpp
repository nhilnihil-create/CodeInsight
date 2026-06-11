#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <iomanip>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int iINF = 100100100;
const ll llINF = 1LL << 60;
ll chmin(ll a, ll b)
{
	return a > b ? b : a;
}
int main()
{
	int n, m;
	cin >> n >> m;
	vector<P> p(m), sortp(m);
	map<P, int> mp;
	rep(i, m) {
		cin >> p[i].first >> p[i].second;
	}
	sortp = p;
	sort(sortp.begin(), sortp.end());
	rep(i, m) {
		mp[sortp[i]] = i;
	}
	vector<string> ans(m);
	int oldYear = sortp[0].first;
	int order = 0;
	rep(i, m) {
		if (oldYear == sortp[i].first)	order++;
		else {
			oldYear = sortp[i].first;
			order = 1;
		}
		ostringstream ss1;
		ss1 << setw(6) << setfill('0') << sortp[i].first;
		string s1(ss1.str());

		ostringstream ss2;
		ss2 << setw(6) << setfill('0') << order;
		string s2(ss2.str());

		ans[i] = s1 + s2;
	}
	rep(i, m)	cout << ans[mp[p[i]]] << endl;
	return 0;
}
