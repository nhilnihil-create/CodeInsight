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

int calc(string S) {
	int res = (S[0] - '0') * 10 + (S[1] - '0');
	res *= 60;
	res += (S[4] - '0');
	res += (S[3] - '0') * 10;
	cout << res << endl;
	return res % 1440;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	int D, G; cin >> D >> G;
	VI P(D), C(D);
	REP(i, D)cin >> P[i] >> C[i];
	int ans = INF;
	REP(i, 1 << D) {
		int cnt = 0;
		int score = 0;
		REP(j, D) {
			if (i&(1 << j)) {
				cnt += P[j];
				score += 100 * (j + 1)*P[j];
				score += C[j];
			}
		}
		//cout << cnt << " " << i << " " << score << endl;
		
		for (int j = D - 1; j >= 0; j--) {
			if (score >= G)break;
			if (i&(1 << j)) {

			}
			else {
				REP(k, P[j] - 1) {
					//cout << k << endl;
					score += 100 * (j + 1);
					cnt++;
					if (score >= G)break;
				}
			}
			if (score >= G)break;
		}
		

		if (score >= G)chmin(ans, cnt);
		//cout << cnt << " " << i << " " << score << endl;
	}

	/*
	int N; cin >> N;
	int cnt[20][1510] = { 0 };
	REP(i, N) {
		string s, t;
		cin >> s >> t;
		int a = calc(s);
		int b = calc(t);
		if (a > b) {
			FOR(j, a, 1440)cnt[i][j]++;
			REP(j, b)cnt[i][j]++;
		}
		else FOR(j, a, b)cnt[i][j]++;
	}
	*/
	cout << ans << endl;
	return 0;
}

