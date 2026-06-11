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

	int N, K; cin >> N >> K;
	VP A(N);
	REP(i, N)cin >> A[i].second >> A[i].first;
	rSORT(A);
	VI best(N + 1, 0);
	VI rem;

	REP(i, N) {
		if (best[A[i].second] == 0)best[A[i].second] = A[i].first;
		else rem.push_back(A[i].first);
	}
	rSORT(rem);
	rSORT(best);
	FOR(i, 1, rem.size()) rem[i] += rem[i - 1];
	FOR(i, 1, best.size()) best[i] += best[i - 1];

	int ans = 0;

	eFOR(i, 1, K) {
		if (i != 1 && best[i - 1] == best[i - 2])break;
		int cnt = 0;
		cnt += i * i;
		cnt += best[i - 1];
		if (K - i - 1>=0 && K - i - 1 < rem.size())cnt += rem[K - i - 1];


		chmax(ans, cnt);
	}





	cout << ans << endl;

	return 0;
}

