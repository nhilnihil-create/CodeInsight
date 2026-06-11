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

using namespace std;

#define int long long

#define rep(i, n) for (int i=0;i<(int)n;++i)
#define rep1(i, n) for (int i=1;i<=(int)n;++i)
#define unless(a) if(!(a))
#define all(a) begin(a),end(a)
#define fst first
#define scd second
#define PB emplace_back
#define PPB pop_back

using ll=long long;
using vi=vector<int>;
using pii=pair<int, int>;

constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); };

bool chmin(int&a,int b){return a>b?(a=b,true):false;}
bool chmax(int&a,int b){return a<b?(a=b,true):false;}
int read(){int a;scanf("%lld",&a);return a;}

const int inf = TEN(9) + 10;
const int mod = TEN(9) + 7;

struct edge {
	int to, cost;
	edge(int to, int cost) : to(to), cost(cost) {}
};

int Q;

signed main()
{
	string s; cin >> s;
	int n = s.size();
	s += "??";

	string t = "";

	rep(i, n) {
		if (s[i] == 'A') {
			t += 'A';
		} else if (s[i] == 'B') {
			if (s[i + 1] == 'C') {
				t += 'X';
				i++;
			} else {
				t += '/';
			}
		} else {
			t += '/';
		}
	}

	int ans = 0;
	int a = 0, x = 0;
	t += '/';

	rep(i, t.size() - 1) {
		if (t[i] == 'A') {
			a++;
		} else if (t[i] == 'X') {
			ans += a;
			x++;
		} else {
			a = x = 0;
		}
	}

	cout << ans << endl;
}
