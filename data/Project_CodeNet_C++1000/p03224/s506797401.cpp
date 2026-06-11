#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second
template<typename A, typename B> inline bool chmax(A &a, B b) { if (a<b) { a=b; return 1; } return 0; }
template<typename A, typename B> inline bool chmin(A &a, B b) { if (a>b) { a=b; return 1; } return 0; }
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll INF = 1ll<<30;
const ll longINF = 1ll<<60;
const ll MOD = 1000000007;
const double EPS = 1e-9;
const bool debug = 0;
//---------------------------------//

int main() {
	int N;
	cin >> N;
	
	int sum = 0, c = 1;
	while (sum < N) {
		sum += c;
		c++;
	}
	// <cまで加える
	
	vector<vector<int> > ans;
	if (sum == N) {
		ans.resize(c);
		int cur = 1;
		REP(i, c) {
			REP(j, i) {
				ans[j].push_back(cur);
				ans[i].push_back(cur);
				cur++;
			}
		}
	}
	
	
	if (ans.empty()) puts("No");
	else {
		puts("Yes");
		cout << ans.size() << endl;
		REP(i, ans.size()) {
			printf("%d", ans[i].size());
			REP(j, ans[i].size()) printf(" %d", ans[i][j]);
			puts("");
		}
	}
	
	return 0;
}
