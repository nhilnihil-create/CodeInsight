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

int L, N;
VP ans;
VI cost;
VI tmp;
map<int, bool>F;


void doubling(int a) {
	if (a == 2) return;
	if (a % 2) {
		tmp.push_back(--a);
		if (a != 2) {
			tmp.push_back(a / 2);
			F[a / 2] = 1;
			a /= 2;
			doubling(a);
		}
	}
	else {
		tmp.push_back(a / 2);
		F[a / 2] = 1;
		a /= 2;
		doubling(a);
	}
}


void kakeru() {
	fore(i, cost)i *= 2;
	ans.push_back(pii(N - 1, N));
	ans.push_back(pii(N - 1, N));
	cost.push_back(1);
	cost.push_back(0);
	N++;
}
void purasu(int L) {
	ans.push_back(pii(0, N - 1));
	cost.push_back(L);
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	ans.push_back(pii(0, 1));
	ans.push_back(pii(0, 1));
	cost.push_back(0);
	cost.push_back(1);
	N = 2;
	cin >> L;
	if (L == 2) {
		cout << N << " " << ans.size() << endl;
		REP(i, ans.size()) cout << ans[i].first + 1 << " " << ans[i].second + 1 << " " << cost[i] << endl;

		return 0;
	}

	doubling(L);
	SORT(tmp);
	fore(i, tmp) {
		//cout << i << endl;
		if (F[i])kakeru();
		else purasu(i);
	}
	cout << N << " " << ans.size() << endl;
	REP(i, ans.size()) cout << ans[i].first + 1 << " " << ans[i].second + 1 << " " << cost[i] << endl;

	return 0;
}

