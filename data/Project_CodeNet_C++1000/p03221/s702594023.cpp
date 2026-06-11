#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

lli n, m;

int main(void){
	cin >> n >> m;
	vector<pair<lli, lli>> a(m);
	map<pair<lli, lli>, lli> id;
	rep(i, m){
		lli p, y;
		cin >> p >> y;
		a[i] = {p, y};
		id[a[i]] = i;
	}
	sort(a.begin(), a.end());
	vector<string> ans(m);
	lli i = 0;
	while(i < m){
		lli num = a[i].first;
		lli od = 1;
		while(i < m && a[i].first == num){
			ostringstream pre, suf;
			pre << setfill('0') << setw(6) << a[i].first;
			suf << setfill('0') << setw(6) << od;
			lli x = id[a[i]];
			ans[x] = pre.str()+suf.str();
			i++;
			od++;
		}
	}
	rep(i, m){
		cout << ans[i] << endl;
	}
	return 0;
}
