//#pragma GCC optimize ("-O3","unroll-loops")
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
#include<iterator>
#include<complex>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<time.h>
#include <random>

using namespace std;

#define REP(i, n) for(int i = 0;i < n;++i)
#define REPR(i, n) for(int i = n-1;i >= 0;--i)
#define FOR(i, m, n) for(int i = m;i < n;++i)
#define FORR(i, m, n) for(int i = m-1;i >= n;--i)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define REVERSE(v,n) reverse(v,v+n);
#define VREVERSE(v) reverse(v.begin(), v.end())
#define ll long long
#define pb(a) push_back
#define print(x) cout<<(x)<<'\n'
#define pe(x) cout<<(x)<<" "
#define lb(v,n) lower_bound(v.begin(), v.end(), n)
#define ub(v,n) upper_bound(v.begin(), v.end(), n)
#define int long long
#define all(x) (x).begin(), (x).end()
#define print_space(v) REP(i,v.size())cout << v[i] << ((i == v.size() - 1) ? "\n" : " ")
//#define double long double
//#define double float
template<typename T1, typename T2> inline void chmin(T1 & a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1& a, T2 b) { if (a < b) a = b; }
typedef pair<int, int>P;
const int MOD = 998244353; const int MAX = 200060;
const double pi = acos(-1); const double EPS = 1e-12;
const ll INF = 1e18;




void solve() {
	int N; cin >> N;
	vector<int>A(N);
	REP(i, N)cin >> A[i];
	int ok = N, ng = 0;
	while (abs(ok - ng) > 1) {
		int K = (ok + ng) / 2;
		map<int, int>mp;
		bool can = true;
		FOR(i, 1, N) {
			if (can == false)break;
			if (A[i] <= A[i - 1]) {
				if (K == 1) { can = false; break; }
				auto itr = mp.begin();
				while (itr != mp.end()) {
					if (itr->first >= A[i])itr = mp.erase(itr);
					else itr++;
				}
				bool done = false;
				FORR(j, A[i], 0) {
					if (mp[j] == K - 1) { mp.erase(mp.find(j)); }
					else { done = true; mp[j]++; break; }
				}
				if (!done) { can = false; break; }
			}
		}
		if (can)ok = K; else ng = K;
	}
	print(ok);
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	solve();
}
