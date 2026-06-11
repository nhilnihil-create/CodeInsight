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



int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("in.txt", "r", stdin);
	ll N, K;
	cin >> N >> K;
	if(K >= (1<<N)) {
		cout << -1 << '\n';
		return 0;
	}
	if(N == 1) {
		if(K == 1) {
			cout << -1 << '\n';
			return 0;
		} else {
			cout << "0 0 1 1" << '\n';
			return 0;
		}
	}
	ll n = 1<<N;
	vl ret;
	rep(i,0,n) {
		if(i == K) continue;
		ret.pb(i);
	}
	ret.pb(K);
	per(i,0,n) {
		if(i == K) continue;
		ret.pb(i);
	}
	ret.pb(K);
	rep(i,0,sz(ret)) {
		cout << ret[i] << " ";
	}
	cout << '\n';
	return 0;
}
