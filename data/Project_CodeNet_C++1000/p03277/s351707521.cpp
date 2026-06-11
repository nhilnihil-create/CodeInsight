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
#define print(x) cout<<x<<'\n';
#define pe(x) cout<<x<<" ";
#define lb(v,n) lower_bound(v.begin(), v.end(), n);
#define ub(v,n) upper_bound(v.begin(), v.end(), n);
#define int long long
#define all(x) (x).begin(), (x).end()
//#define double long double

using namespace std;

template<class T> inline bool chmin(T & a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<class T> inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

const int MOD = 1e9 + 7;
const ll INF = 1e9;
const double pi = acos(-1);
const double EPS = 1e-10;
typedef pair<int, int>P;
const int MAX = 100020;

template <class Abel> struct BIT {
	const Abel UNITY_SUM = 0;
	vector<Abel>dat;
	BIT(int n):dat(n+1,UNITY_SUM){}
	void init(int n) { dat.assign(n + 1, UNITY_SUM); }

	inline void add(int a, Abel x) {
		for (int i = a; i < (int)dat.size(); i += i & -i)
			dat[i] = dat[i] + x;
	}
	inline Abel sum(int a) {
		Abel res = UNITY_SUM;
		for (int i = a; i > 0; i -= i & -i)
			res = res + dat[i];
		return res;
	}
	inline Abel sum(int a, int b) {
		return sum(b - 1) - sum(a - 1);
	}
};

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll N; cin >> N;
	vector<int>a(N); REP(i, N)cin >> a[i];
	int low = 0, high = 1 << 30;
	const int geta = N + 1;
	while (high - low > 1) {
		int mid = (low + high) / 2;
		ll num = 0;
		BIT<ll>bit(N * 2 + 10);
		int sum = 0;
		bit.add(sum + geta, 1);
		REP(i, N) {
			int val;
			if (a[i] <= mid)val = 1; else val = -1;
			sum += val;
			num += bit.sum(1, sum + geta);
			bit.add(sum + geta, 1);
		}
		if (num > (N + 1) * N / 2 / 2)high = mid;
		else low = mid;
	}
	print(high);
}

