#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <functional>
#include <climits>
#include <cstring>

using namespace std;

#define int long long
#define rep(i, n) for (int i=0;i<(int)(n);++i)
#define rep1(i, n) for (int i=1;i<=(int)(n);++i)
#define range(i, l, r) for (int i=l;i<(int)(r);++i)
#define rrange(i, l, r) for (int i=r-1;i>=(int)(l);--i)
#define unless(a) if(!(a))
#define all(a) begin(a),end(a)
#define fst first
#define scd second
#define PB emplace_back
#define PPB pop_back

using vi=vector<int>;
using pii=pair<int, int>;
using ll=long long;

bool chmin(int&a,int b){return a>b?(a=b,true):false;}
bool chmax(int&a,int b){return a<b?(a=b,true):false;}
int read(){int a;scanf("%lld",&a);return a;}

const int inf = 1e9 + 10;
const int mod = 1e9 + 7;

inline ll mod_pow(ll a, ll x, ll m)
{
	if (x == 0) return 1;

	ll res = mod_pow(a, x / 2, m);

	res *= res;
	res %= m;

	if (x % 2) {
		res *= a;
		res %= m;
	}

	return res;
}

int counter[26];

signed main()
{
	int N; cin >> N;
	string S; cin >> S;

	rep(i, N) {
		int c = S[i] - 'a';
		counter[c]++;
	}

	int ans = 1;

	rep(i, 26) (ans *= counter[i] + 1) %= mod;

	ans += mod - 1;
	ans %= mod;

	cout << ans << endl;
}

