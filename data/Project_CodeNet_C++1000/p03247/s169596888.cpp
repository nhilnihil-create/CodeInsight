#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize("unroll-loops")
//#pragma warning(disable : 4996)

#ifdef _MSC_VER
#include <intrin.h>
#define __builtin_popcount __popcnt
#define __builtin_popcountll __popcnt64
#endif

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
#include<random>
#include<array>


using namespace std;

#define REP(i, n) for(int i = 0;i < (n);++i)
#define REPR(i, n) for(int i = n-1;i >= 0;--i)
#define FOR(i, m, n) for(int i = m;i < n;++i)
#define FORR(i, m, n) for(int i = m-1;i >= n;--i)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define REVERSE(v,n) reverse(v,v+n);
#define VREVERSE(v) reverse(v.begin(), v.end())
#define ll long long
#define print(x) cout<<(x)<<'\n'
#define pe(x) cout<<(x)<<" "
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define lb(v,n) lower_bound(v.begin(), v.end(), (n))
#define ub(v,n) upper_bound(v.begin(), v.end(), (n))
#define int long long
#define double long double
#define all(x) (x).begin(), (x).end()
#define print_space(v) REP(i,v.size())cout << v[i] << ((i == v.size() - 1) ? "\n" : " ")
template<typename T1, typename T2> inline void chmin(T1 & a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1& a, T2 b) { if (a < b) a = b; }
typedef pair<int, int>pii;
typedef pair<long long, long long>pll;
typedef array<int, 3> arr3;
std::random_device rd;
std::mt19937 mt(rd());
constexpr ll MOD = 998244353; constexpr int MAX = 200050;
const double pi = acosl(-1); constexpr double EPS = 1e-10;
constexpr ll INF = 1e16;
void yes(bool c) { if (c)print("Yes"); else print("No"); };

//LRDU
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
char dir[4] = { 'L','R','D','U' };

void solve() {
	int N; cin >> N;
	vector<int>X(N), Y(N);
	set<int>st;
	REP(i, N) {
		cin >> X[i] >> Y[i];
		st.insert(abs(X[i] + Y[i]) % 2);
	}
	if (st.size() >= 2) {
		print(-1); return;
	}
	vector<int>v;
	REPR(i, 31) {
		v.push_back(1LL << i);
	}
	if (*st.begin() == 0)v.push_back(1);
	int M = v.size();
	print(M);
	print_space(v);
	REP(i, N) {
		ll x = 0, y = 0;
		string res;
		REP(j, M) {
			ll nd = 0;
			ll dif = 1e18;
			REP(k, 4) {
				ll nx = x + dx[k] * v[j];
				ll ny = y + dy[k] * v[j];
				ll d = abs(nx - X[i]) + abs(ny - Y[i]);
				if (d < dif) {
					dif = d;
					nd = k;
				}
			}
			res += dir[nd];
			x += dx[nd] * v[j];
			y += dy[nd] * v[j];
		}
		print(res);
	}
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	//int q; cin >> q;
	//while (q--)
	solve();
}

