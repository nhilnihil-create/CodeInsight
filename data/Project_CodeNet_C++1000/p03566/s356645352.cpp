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
	int time = 0;
	VI T(N), V(N);
	REP(i, N) {
		cin >> T[i];
		if (i != 0)T[i] += T[i - 1];
	}
	REP(i, N)cin >> V[i];
	double v[101010];
	REP(i, 101010)v[i] = INF;
	int k = 0;
	int now = 0;
	while (now <= T[k] * 2) {
		//cout << now << endl;
		v[now] = min(v[now], (double)V[k]);
		now++;
		if (now > T[k] * 2) {
			k++;
			if(k!=N)v[now - 1] = min(v[now - 1], (double)V[k]);
		}
		if (k == N)break;
	}

	v[0] = 0;
	eFOR(i, 1, T[N - 1] * 2) {
		v[i] = min(v[i], v[i - 1] + 0.5);
	}
	v[T[N - 1] * 2] = 0;
	for (int i = T[N - 1] * 2 - 1; i > 0; i--) {
		v[i] = min(v[i], v[i + 1] + 0.5);
	}
	double ans = 0;

	eFOR(i, 1, T[N - 1] * 2) {
		//cout << v[i] << " " << i << endl;
		double tmp = (v[i] + v[i - 1]);
		
		
		ans += tmp * 0.25;
		//cout << i << " " << ans << endl;
	}

	

	printf("%.10f\n", ans);

	return 0;
}

