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


set<ll> s, t;


ll cul(ll x,bool flag,bool judge) {
	//flag trueでshrineを探す
	ll right, left;

	if (flag) {
		auto ite = s.lower_bound(x);
		
			if (ite == s.end())right= 100000000000;
			else {
				right = abs(x - *ite);
				if (!judge) {
					right += cul(*ite,false,true);
				}
			}
		
			if (ite == s.begin())left= 100000000000;
			else {
				ite--;
				left = abs(x - *ite);
				if (!judge) {
					left += cul(*ite, false, true);
				}
			}

	}
	else {
		auto ite = t.lower_bound(x);

		if (ite == t.end())right = 100000000000;
		else {
			right = abs(x - *ite);
			if (!judge) {
				right += cul(*ite, true, true);
			}
		}

		if (ite == t.begin())left = 100000000000;
		else {
			ite--;
			left = abs(x - *ite);
			if (!judge) {
				left += cul(*ite, true, true);
			}
		}
	}
	//cout <<"  "<< min(right, left) << endl;
	return min(right, left);
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	ll A, B; cin >> A >> B;
	ll Q; cin >> Q;

	FOR(i, 0, A){
		ll x; cin >> x;
		s.insert(x);
	}
	FOR(i, 0, B) {
		ll x; cin >> x;
		t.insert(x);
	}
	FOR(i, 0, Q) {
		ll x; cin >> x;

		cout <<min(cul(x,true,false),cul(x,false,false)) << endl;

	}



	return 0;
}