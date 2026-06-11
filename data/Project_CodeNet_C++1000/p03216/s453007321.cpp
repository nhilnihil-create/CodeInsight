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
	string S; cin >> S;

	int Q; cin >> Q;
	REP(i, Q) {
		int a; cin >> a;
		int d = 0, m = 0, c = 0;
		int dm = 0;
		int s = 0, t = 0;
		int ans = 0;
		while (t - s < a && t<N) {
			//cout << ans << endl;
			//cout << s << " " << t << endl;
			//cout << d << " " << m << " " << dm << endl;
			if (S[t] == 'D') {
				d++;
			}
			if (S[t] == 'M') {
				dm += d;
				m++;
			}
			if (S[t] == 'C') {
				ans += dm;
			}

			if (t - s + 1 >= a) {
				if (S[s] == 'D') {
					d--;
					dm -= m;
				}
				if (S[s] == 'M') {
					m--;
					//dm -= d;
				}
				s++;
			}
			t++;
		}
		cout << ans << '\n';
	}
}