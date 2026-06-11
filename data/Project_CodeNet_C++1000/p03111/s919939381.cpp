#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> P;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()

constexpr auto INF = INT_MAX/2;
constexpr auto MOD = 1000000007;

int main() {

	int n;
	vi L(3);
	cin >> n >> L[0] >> L[1] >> L[2];
	vi l(n);
	rep(i, n)cin >> l[i];
	sort(all(l));
	rep(i, 3)l.push_back(INF);

	int ans = INF;

	do {
		vvi leng(3, vi(0));
		int k = 0;

		rep(i, 3) {
			while (k<n+3) {
				if (l[k] != INF)leng[i].push_back(l[k]);
				k++;
				if (l[k - 1] == INF)break;
			}
		}

		if (leng[0].size() * leng[1].size() * leng[2].size() == 0)continue;

		vi sum(3,0);
		rep(i, 3)rep(j, leng[i].size()) sum[i]+= leng[i][j];

		int mp = 0;
		rep(i, 3)mp += 10 * leng[i].size() - 10 + abs(sum[i] - L[i]);
		
		ans = min(ans, mp);

	} while (next_permutation(all(l)));

	cout << ans << endl;
}