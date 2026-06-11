#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef set<int> si;
typedef pair<int,int> pii;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define per(i,a,b) for(int i=(b)-1; i>=(a); --i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define F first
#define S second

const int INF = 1e9;
int n,k,q;
vi a;

int solve(int mn) {
	vector<vi> b;
	vi loc;
	for(int i=0; i<n; ++i) {
		if(a[i] >= mn) {
			loc.pb(a[i]);
		} else {
			if(!loc.empty()) {
				b.pb(loc);
				loc.clear();
			}
		}
	}
	if(!loc.empty())
		b.pb(loc);
 
	vi cand;
	for(int i=0; i<(int)b.size(); ++i) {
		sort(all(b[i]));
		int m = sz(b[i]);
		for(int j=0; j<m-k+1; ++j) {
			cand.pb(b[i][j]);
		}
	}
	if(sz(cand) < q) {
		return INF;
	}
	sort(all(cand));
	return cand[q-1]-cand[0];
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("in.txt", "r", stdin);
	cin >> n >> k >> q;
	a.resize(n);
	set<int> s;
	rep(i,0,n) {
		cin >> a[i];
		s.insert(a[i]);
	}
	int ret = INF;
	for(auto mn : s) {
		ret = min(ret, solve(mn));
	}
	cout << ret << '\n';
	return 0;
}
