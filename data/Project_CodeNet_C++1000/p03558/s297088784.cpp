#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, a) for (int i = 0; (i) < (int) (a); (i)++)
#define reps(i, a, b) for (int i = (int) (a); (i) < (int) (b); (i)++)
#define rrep(i, a) for (int i = (int) a-1; (i) >= 0; (i)--)
#define rreps(i, a, b) for (int i = (int) (a)-1; (i) >= (int) (b); (i)--)
#define MP(a, b) make_pair((a), (b))
#define PB(a) push_back((a))
#define all(v) (v).begin(), (v).end()
#define PERM(v) next_permutation(all(v))
#define UNIQUE(v) sort(all(v));(v).erase(unique(all(v)), v.end())
#define CIN(type, x) type x;cin >> x
#define TRUE__  "YES"
#define FALSE__ "NO"
#define PRINT(f) if((f)){cout << (TRUE__) << endl;}else{cout << FALSE__ << endl;}
#define RS resize
#define CINV(v, N) do {\
	v.RS(N);\
	rep(i, N) cin >> v[i];\
} while (0);
#define RCINV(v, N) do {\
	v.RS(N);\
	rrep(i, N) cin >> v[i];\
} while (0);

#define MOD 1000000007

void init();
void solve();

signed main()
{
	init();
	solve();
}

int K;
priority_queue<pair<int, pair<int, int> > > q;
//                 cost        s    t
vector<int> cost;
vector<bool> f;
const int INF = INT_MAX;

void init()
{
	cin >> K;
	cost.RS(K, INF);
}


void solve()
{
	cost[1] = 1;
	q.push(MP(-1, MP(1, 10 % K)));
	q.push(MP(-2, MP(1, 2 % K)));
	while (!q.empty()) {
		auto x = q.top();
		q.pop();
		int s = x.second.first;
		int t = x.second.second;
		int c = -x.first;
		if (cost[t] != INF) continue;
		cost[t] = c;
		q.push(MP(-c, MP(t, t * 10 % K)));
		q.push(MP(-c-1, MP(t, (t + 1) % K)));
	}
	cout << cost[0] << endl;
}



