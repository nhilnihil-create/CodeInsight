#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	vector<ll> a(3);
	int k;
	cin >> a.at(0) >> a.at(1) >> a.at(2);
	cin >> k;
	sort(a.begin(), a.end());
	rep(i, k) a.at(2) *= 2;
	ll ans = 0;
	rep(i, 3) ans += a.at(i);
	cout << ans << endl;
}