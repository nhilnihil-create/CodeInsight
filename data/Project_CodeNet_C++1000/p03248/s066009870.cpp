#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef set<int> si;
typedef set<ll> sl;
typedef pair<int,int> pii;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define per(i,a,b) for(int i=(b)-1; i>=(a); --i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define F first
#define S second

bool isValid(string s) {
	int n = s.size();
	if(s[n-1] == '1') {
		return false;
	} else if(s[0] == '0') {
		return false;
	}
	rep(i,0,n/2) {
		if(s[i] != s[n-2-i]) {
			return false;
		}
	}
	return true;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("in.txt", "r", stdin);
	string s;
	cin >> s;
	int n = s.size();
	if(!isValid(s)) {
		cout << -1 << '\n';
		return 0;
	}
	vi v;
	rep(i,0,n) {
		if(s[i] == '1') {
			v.pb(i);
		}
	}
	v.pb(v.back()+1);
	vector<pii> ret;
	rep(i,0,sz(v)-1) {
		ret.pb(mp(i,i+1));
	}
	int t = sz(v);
	rep(i,1,sz(v)) {
		int x = v[i] - v[i-1] - 1;
		rep(j,0,x) {
			ret.pb(mp(i,t));
			t++;
		}
	}
	rep(i,0,sz(ret)) {
		cout << ret[i].F+1 << " " << ret[i].S+1 << '\n';
	}
	return 0;
}
