#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<math.h>
using namespace std;
typedef long long ll;
#define int long long
typedef vector<int> VI;
typedef pair<int, int> pii;
typedef vector<pii> VP;
typedef vector<string> VS;
typedef priority_queue<int> PQ;
template<class T>bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }
#define fore(i,a) for(auto &i:a)
#define REP(i,n) for(int i=0;i<n;i++)
#define eREP(i,n) for(int i=0;i<=n;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define eFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define SORT(c) sort((c).begin(),(c).end())
#define rSORT(c) sort((c).rbegin(),(c).rend())
#define LB(x,a) lower_bound((x).begin(),(x).end(),(a))
#define UB(x,a) upper_bound((x).begin(),(x).end(),(a))
#define INF 1000000000
#define LLINF 9223372036854775807
#define mod 1000000007
//priority_queue<int,vector<int>, greater<int> > q2;



signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N; cin >> N;
	int A, B, C; cin >> A >> B >> C;
	int ans = LLINF;
	VI L(N);
	REP(i, N)cin >> L[i];
	SORT(L);
	do {
		int cnt = LLINF;
		VI sum(N + 1, 0);
		REP(i, N)sum[i + 1] = sum[i] + L[i];

		eFOR(i,1, N - 2) {
			eFOR(j, i + 1, N - 1) {
				eFOR(k, j + 1, N) {
					int tmp = 0;
					tmp += abs(sum[i] - A);
					tmp += abs(sum[j] - sum[i] - B);
					tmp += abs(sum[k] - sum[j] - C);

					tmp += 10 * (i - 1);
					tmp += 10 * (j - i - 1);
					tmp += 10 * (k - j - 1);

					chmin(cnt, tmp);
				}
			}
		}

		chmin(ans, cnt);

	} while (next_permutation(L.begin(), L.end()));






	cout << ans << endl;

	return 0;
}

