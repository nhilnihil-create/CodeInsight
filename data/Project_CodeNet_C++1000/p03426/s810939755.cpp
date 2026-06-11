#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <string.h>
#include <cstdio>
#include <tuple>
#include <numeric>
#include <time.h>
#include <chrono>
#ifdef _MSC_VER
#  include <intrin.h>
#  define __builtin_popcount __popcnt
#endif
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define REP(i,a,b) for(ll i=a;i>b;i--)
#define CST(x) cout<<fixed<<setprecision(x)//小数点以下の桁数指定
#define ct(a) cout<<a<<endl
#define rep(i,n) for(int i=0;i<(n);i++)
#define repl(i,l,r) for(int i=(1);i<(r);i++)
#define per(i, n) for(int i = ((n)-1); i >= 0; i--)
static const double pi = 3.141592653589793;
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
const ll INF = (1LL << 31) - 1;
const ll mod = 1e9 + 7;


ll H, W, D,Q;
vector<pair<ll,pair<ll,ll>>> A;
ll B[100000];//次のマスまでの消費コスト

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> H >> W >> D;
	A.resize(H*W);

	ll idx = 0;
	FOR(i, 0, H)FOR(j, 0, W) {
		cin >> A[idx].first;
		A[idx].second.first = i;
		A[idx].second.second = j;
		idx++;
	}

	sort(A.begin(), A.end());

	for (int i = 0; i + D < H * W; i++) {
		//cout <<" "<< A[i].first << endl;
		B[A[i].first]
			= abs(A[i].second.first - A[i + D].second.first) + abs(A[i].second.second - A[i + D].second.second);
	}

	FOR(i, D+1, H*W + 1) {
		B[i] += B[i - D];
	}


	cin >> Q;
	FOR(i, 0, Q) {
		ll L, R; cin >> L >> R;
		ll ans = 0;
		
		if(L>D)cout << B[R-D]-B[L-D] << endl;
		else if(R>D)cout << B[R-D] << endl;
		else cout << 0 << endl;
	}





	return 0;
}