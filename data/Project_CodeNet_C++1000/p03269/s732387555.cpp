#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>
#include<limits.h>
#include<cassert>
#include <fstream>
#include <time.h>
#include <iterator>
#include<random>



#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define REVERSE(v,n) reverse(v,v+n);
#define VREVERSE(v) reverse(v.begin(), v.end());
#define ll long long
#define pb(a) push_back(a)
#define m0(x) memset(x,0,sizeof(x))
#define print(x) cout<<x<<endl;
#define pe(x) cout<<x<<" ";
#define lb(v,n) lower_bound(v.begin(), v.end(), n);
#define ub(v,n) upper_bound(v.begin(), v.end(), n);
#define int long long
#define all(x) (x).begin(), (x).end()
using namespace std;
int MOD = (ll)1000000000 + 7;
const ll INF = 1e17;
const double pi = acos(-1);
const double EPS = 1e-10;
typedef pair<int, int>P;
const int MAX = 500050;

struct edge
{
	int to, cost;
};

vector<edge> G[30];
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int L; cin >> L;
	L--;
	int K, r;
	REPR(i, 20) {
		if (L - (1 << i) >= -1) {
			K = i;
			r = L - (1 << i) + 1;
			break;
		}
	}
	int N = K + 1;
	int M = 0;
	REP(i, N - 1) {
		G[i].push_back({ i + 1,1 << i });
		G[i].push_back({ i + 1,0 });
		M += 2;
	}
	int mx = 1 << K;
	REPR(i, 20) {
		if (r&(1 << i)) {
			G[i].push_back({ N - 1,mx });
			mx += 1 << i;
			M++;
		}
	}
	pe(N)print(M);
	REP(i, 30) {
		for (auto x : G[i]) {
			pe(i + 1)pe(x.to + 1)print(x.cost);
		}
	}
}