#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int INF = 1e9;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<P> v;
	rep(i,m){
		int a, b;
		cin >> a >> b;
		--a; --b;
		v.emplace_back(b, a);
	}
	sort(v.begin(), v.end());
	int ans = 0;
	int l = -1, r = INF;
	rep(i,m){
		chmax(l, v[i].second);
		chmin(r, v[i].first);
		if(r <= l){
			++ans;
			l = v[i].second;
			r = v[i].first;
		}
	}
	if(r != INF) ++ans;
	cout << ans << endl;
	return 0;
}