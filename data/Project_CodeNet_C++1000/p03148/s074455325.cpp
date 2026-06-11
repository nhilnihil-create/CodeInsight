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

ll n, k;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("in.txt", "r", stdin);
	cin >> n >> k;
	// pair<score, type> 
	vector<pair<ll, ll> > food;
	rep(i,0,n) {
		ll t, d;
		cin >> t >> d;
		food.pb(mp(d, t));
	}
	sort(food.rbegin(), food.rend());

	set<ll> have;
	priority_queue<ll> Q;
	ll locret = 0;
	ll ret = 0;
	rep(i,0,k) {
		ll d = food[i].F;
		ll t = food[i].S;

		if(have.count(t)) {
			Q.push(-d);
		} else {
			have.insert(t);
		}

		locret += d;
	}

	ret = locret + (ll)have.size() * have.size();

	rep(i,k,n) {
		ll d = food[i].F;
		ll t = food[i].S;

		if(Q.empty()) break;
		ll minD = -Q.top();
		Q.pop();

		if(have.count(t)) {
			Q.push(-d);
		} else {
			have.insert(t);
		}

		ll x = have.size();
		locret = locret + d - minD;
		ret = max(ret, locret + x * x);
	}

	cout << ret << '\n';
	return 0;
}
