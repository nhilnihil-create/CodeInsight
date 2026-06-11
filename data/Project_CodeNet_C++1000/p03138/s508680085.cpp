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
	int bi[50] = { 0 };
	REP(i, N) {
		int a; cin >> a;
		int j = 0;
		while (a) {
			bi[j++] += a % 2;
			a /= 2;
		}
	}
	int dp[50][2] = { 0 };
	REP(i, 50)dp[i][1] = -1;
	for (int i = 48; i >= 0; i--) {
		if ((1LL << i) > K) {
			chmax(dp[i][0], dp[i + 1][0] + (1LL << i)*bi[i]);
		}
		else if ((1LL << i)&K) {
			chmax(dp[i][0], dp[i + 1][0] + (1LL << i)*(N - bi[i]));
			chmax(dp[i][1], dp[i + 1][0] + (1LL << i)*bi[i]);
			if (dp[i + 1][1] != -1)chmax(dp[i][1], dp[i + 1][1] + (1LL << i)*(N - bi[i]));
			chmax(dp[i][1], dp[i + 1][1] + (1LL << i)*bi[i]);
		}
		else {
			chmax(dp[i][0], dp[i + 1][0] + (1LL << i)*bi[i]);
			chmax(dp[i][1], dp[i + 1][1] + (1LL << i)*(N - bi[i]));
			chmax(dp[i][1], dp[i + 1][1] + (1LL << i)*bi[i]);
		}
	}






	cout << max(dp[0][0], dp[0][1]) << endl;

	return 0;
}

