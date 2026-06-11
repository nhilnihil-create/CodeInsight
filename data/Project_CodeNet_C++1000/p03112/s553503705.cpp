#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int a, b, q;
	cin >> a >> b >> q;
	vector<ll> s(1);
	vector<ll> t(1);
	s.at(0) = -1000000000000;
	t.at(0) = -1000000000000;
	rep(i, a){
		ll in;
		cin >> in;
		s.push_back(in);
	}
	rep(i, b){
		ll in;
		cin >> in;
		t.push_back(in);
	}
	s.push_back(1000000000000);
	t.push_back(1000000000000);
	vector<ll> an(q);
	rep(i, q){
		ll x;
		cin >> x;
		int k = lower_bound(s.begin(), s.end(), x) - s.begin();
		int l = lower_bound(t.begin(), t.end(), x) - t.begin();
		vector<ll> ans(8);
		ans.at(0) = abs(s.at(k)-x) + abs(t.at(l) - s.at(k));
		ans.at(1) = abs(s.at(k)-x) + abs(t.at(l-1) - s.at(k));
		ans.at(2) = abs(x-s.at(k-1)) + abs(t.at(l) - s.at(k-1));
		ans.at(3) = abs(x-s.at(k-1)) + abs(t.at(l-1) - s.at(k-1));
		ans.at(4) = abs(t.at(l)-x) + abs(s.at(k) - t.at(l));
		ans.at(5) = abs(t.at(l)-x) + abs(s.at(k-1) - t.at(l));
		ans.at(6) = abs(x-t.at(l-1)) + abs(s.at(k) - t.at(l-1));
		ans.at(7) = abs(x-t.at(l-1)) + abs(s.at(k-1) - t.at(l-1));
		ll anser = 1000000000000;
		rep(i, 8){
			anser = min(anser, ans.at(i));
		}
		an.at(i) = anser;
	}
	rep(i, q){
		cout << an.at(i) << endl;
	}
	return 0;
}