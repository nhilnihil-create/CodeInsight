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
#include <cmath>
#include <numeric>
#include <iomanip>

using namespace std;

#define int long long

#define rep(i, n) for (int i=0;i<(int)n;++i)
#define rep1(i, n) for (int i=1;i<=(int)n;++i)
#define rrep(i, n) for (int i=(int)n-1;i>=0;--i)
#define rrep1(i, n) for (int i=n;i>=1;--i)
#define range(i, l, r) for (int i=l;i<(int)r;++i)
#define rrange(i, l, r) for (int i=(int)r-1;i>=(int)l;--i)
#define unless(a) if(!(a))
#define all(a) begin(a),end(a)
#define fst first
#define scd second
#define PB emplace_back
#define PPB pop_back

using ll=long long;
using vi=vector<int>;
using pii=pair<int, int>;
using ld=long double;

bool chmin(int&a,int b){return a>b?(a=b,true):false;}
bool chmax(int&a,int b){return a<b?(a=b,true):false;}
constexpr int TEN(int n){return n==0?1:10*TEN(n-1);}

const int mod = TEN(9)+7;
const int inf = TEN(18) * 3 + 10;

int N, Q;
string S;

int calc(int k)
{
	int ans = 0;

	int cur = 0;
	int m = 0, c = 0;

	range(i, 0, k - 1) {
		if (S[i] == 'M') {
			m++;
		}
		if (S[i] == 'C') {
			c++;
			cur += m;
		}
	}

	/*
   printf("initial: cur = %lld\n", cur);
   printf("[0, %lld]: m = %lld, c = %lld\n", k - 2, m, c);
	*/
	range(i, 1, N) {
		if (S[i - 1] == 'C') {
			c--;
		}
		if (S[i - 1] == 'M') {
			cur -= c;
			m--;
		}

		if (S[i + k - 2] == 'C') {
			cur += m;
			c++;
		}
		if (S[i + k - 2] == 'M') {
			m++;
		}

		if (S[i - 1] == 'D') {
			ans += cur;
			//printf("i = %lld, ans += %lld\n", i, cur);
		}

		//printf("[%lld, %lld]: m = %lld, c = %lld\n", i, i + k - 2, m, c);
	}
	//puts("");

	return ans;
}

signed main()
{
	cin >> N >> S >> Q;

	rep(i, N + 5) S += ' ';

	rep(_, Q) {
		int k; cin >> k;
		cout << calc(k) << endl;
		//calc(k);
	}
}

