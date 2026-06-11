#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

const int MX = 200010;

vi vec[MX];

int main() {
	int H, W, N; cin >> H >> W >> N;
	rep(i, N) {
		int x, y;
		cin >> x >> y; --x; --y;
		vec[x].pb(y);
	}

	rep(i, H) sort(ALL(vec[i]));

	int r = 0;

	rep(i, H-1) {
		if (i > 0 && !binary_search(ALL(vec[i]), r + 1)) {
			r++;
		}
		if (vec[i+1].size() && vec[i+1][0] <= r) {
			cout << i + 1 << endl;
			return 0;
		}		
	}

	cout << H << endl;

	return 0;
}