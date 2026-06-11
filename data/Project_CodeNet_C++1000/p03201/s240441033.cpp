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

int n;
vl a;
map<ll, int> r;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("in.txt", "r", stdin);
	cin >> n;
	a.resize(n);
	rep(i,0,n) {
		cin >> a[i];
	}

	sort(a.rbegin(), a.rend());

	rep(i,0,n) {
		if(r.find(a[i]) != r.end()) {
			r[a[i]]++;
		} else {
			r[a[i]] = 1;
		}
	}

	int ret = 0;

	rep(i,0,n) {
		if(r[a[i]] == 0) continue;
		//cout << i << ", " << a[i] << endl;
		ll x = 2;
		while(x <= 2 * a[i]) {
			if (x <= a[i]) {
				x = 2 * x;
				continue;
			}
			ll y = x - a[i];
			if(r.find(y) == r.end()) break;
			if(a[i] == y) {
				if(r[y] >= 2) {
					ret++;
					r[y] -= 2;
				}
			} else {
				if(r[y] > 0 && r[a[i]] > 0) {
					ret++;
					r[y] -= 1;
					r[a[i]] -= 1;
				}
			}
			break;
		}
	}

	cout << ret << endl;
	return 0;
}
