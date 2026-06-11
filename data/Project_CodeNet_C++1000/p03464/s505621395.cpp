#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define dup(x,y) (((x)+(y)-1)/(y))
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const double EPS = 1e-10;
const int INF = 1e9;
const ll LINF = 1e15;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	rep(i,n) cin >> v[i];
	reverse(ALL(v));
	if (v[0] != 2) cout << -1 << endl;
	else {
		ll l = 2;
		ll r = 3;
		for (int i = 0; i < n; i++) {
			ll k = v[i];
			l = dup(l,k) * k;
			r = dup(r,k) * k;
			if (r - l <= 1) {	
				cout << -1 << endl;
				return 0;
			}
		}
		cout << l << " " << r-1 << endl;
	}
}