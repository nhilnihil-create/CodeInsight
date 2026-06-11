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

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("in.txt", "r", stdin);
	int n;
	cin >> n;
	vl a(n), b(n);
	ll total = 0;
	rep(i,0,n) {
		cin >> a[i] >> b[i];
		total += a[i];
	}
	bool flag = true;
	rep(i,0,n) {
		if(a[i] != b[i]) {
			flag = false;
			break;
		}
	}
	if(flag) {
		cout << 0 << '\n';
		return 0;
	}
	ll mn = 1e18;
	rep(i,0,n) {
		if(a[i] > b[i]) {
			mn = min(mn, b[i]);
		}
	}
	cout << total - mn << '\n';
	return 0;
}
