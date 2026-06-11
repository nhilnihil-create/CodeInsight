#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<pair<ll, int>> v;
	vector<ll> a(n), b(n);
	ll sum = 0;
	rep(i,n){
		cin >> a[i] >> b[i];
		sum += a[i] + b[i];
		v.emplace_back(a[i]+b[i], i);
	}
	sort(v.rbegin(), v.rend());
	ll tak = 0, aok = 0;
	rep(i,n){
		if(i%2 == 0) tak += a[v[i].second];
		else aok += b[v[i].second];
	}
	ll ans = tak - aok;
	cout << ans << endl;
	return 0;
}