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

int n, q;
string s;

int get(int idx, vector<pair<char, int> >& r) {
	rep(i,0,q) {
		if(s[idx] == r[i].F) {
			idx += r[i].S;
		}
		if(idx < 0 || idx >= n) return idx;
	}
	return idx;
}

int solve(vector<pair<char, int> >& r) {
	int ret = 0;
	int low = 0;
	int hig = n;
	while(low<hig) {
		int mid = (low+hig) / 2 + 1;
		if(get(mid,r) == -1) {
			low = mid;
		} else {
			hig = mid-1;
		}
	}
	if(get(low,r) == -1) {
		ret += (low + 1);
	}
	low = 0;
	hig = n;
	while(low<hig) {
		int mid = (low+hig)/2;
		if(get(mid,r) == n) {
			hig = mid;
		} else {
			low = mid+1;
		}
	}
	ret += (n - low);
	return n - ret;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("in.txt", "r", stdin);
	cin >> n >> q;
	cin >> s;
	vector<pair<char, int> > r(q);
	rep(i,0,q) {
		char t, d;
		cin >> t >> d;
		if(d == 'R') {
			r[i] = mp(t,1);
		} else {
			r[i] = mp(t,-1);
		}
	}
	cout << solve(r) << '\n';
	return 0;
}
