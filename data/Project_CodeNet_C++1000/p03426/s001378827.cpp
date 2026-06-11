#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
constexpr auto INF = INT_MAX >> 1;
constexpr auto LINF = 5000000000000000LL;
constexpr auto MOD = 1000000007;

int main() {

	int h, w, d;
	cin >> h >> w >> d;

	V<V<T>> place(d);

	rep(i, h)rep(j, w) {
		int a;
		cin >> a;
		a--;
		place[a % d].push_back(T(a, i, j));
	}
	
	rep(i, d)sort(all(place[i]));
	vvi sum(d, { 0 });

	rep(i, d)rep(j, place[i].size() - 1) {
		int dist = 0;
		dist += abs(get<1>(place[i][j + 1]) - get<1>(place[i][j]));
		dist += abs(get<2>(place[i][j + 1]) - get<2>(place[i][j]));
		sum[i].push_back(sum[i][sum[i].size() - 1] + dist);
	}

	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		l--;r--;
		cout << sum[r % d][r / d] - sum[l % d][l / d] << endl;
	}
}