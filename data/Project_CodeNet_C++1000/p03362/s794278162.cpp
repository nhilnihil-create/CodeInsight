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

ll N,ans;
vector<ll> A;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;


	ll now = 11;
	while (A.size() < N) {
		bool flag = true;
		for (ll i = 2; i*i <= now; i++) {
			if (now%i == 0) {
				flag = false;
				break;
			}
		}
		if (flag) {
			A.push_back(now);
		}
		now += 10;
	}
	FOR(i, 0, N)cout << A[i] << " ";
	cout << endl;



}