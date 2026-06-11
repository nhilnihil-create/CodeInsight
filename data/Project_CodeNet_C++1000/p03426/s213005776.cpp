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

int dist(pii a, pii b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int H, W, D;
	cin >> H >> W >> D;
	map<int, pii>mp;
	REP(i, H) {
		REP(j, W) {
			int a; cin >> a;
			a--;
			mp[a] = pii(i, j);
		}
	}

	vector<VI> sum(D, VI(H*W / D + 10, 0));
	REP(i, D) {
		int j = i;
		int a = 1;
		while (j + D < H * W) {
			sum[i][a] += sum[i][a - 1] + dist(mp[j], mp[j + D]);
			j += D;
			a++;
		}
	}
	int Q; cin >> Q;
	REP(i, Q) {
		
		int L, R; cin >> L >> R;
		L--; R--;
		
		cout << sum[R%D][R / D] - sum[L%D][L / D] << endl;
	}


	return 0;
}

