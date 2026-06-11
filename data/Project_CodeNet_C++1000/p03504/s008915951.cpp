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
#define rep(i, n) for (int i=0;i<(int)n;++i)
#define rep1(i, n) for (int i=1;i<=(int)n;++i)
#define unless(a) if(!(a))
#define all(a) begin(a),end(a)
#define fst first
#define scd second
#define PB emplace_back
#define PPB pop_back

using vi=vector<int>;
using pii=pair<int, int>;

bool chmin(int&a,int b){return a>b?(a=b,true):false;}
bool chmax(int&a,int b){return a<b?(a=b,true):false;}
int read(){int a;scanf("%lld",&a);return a;}

using Data = pair<pii, int>;

int N, C;

vector<pii> a[30];
int used[30][100010];
int imos[30][100010];

signed main()
{
	cin >> N >> C;


	rep(i, N) {
		int s, t, c; cin >> s >> t >> c;
		--c;
		a[c].PB(pii(s, t));
	}

	rep(i, C) sort(all(a[i]));

	rep(c, C) {
		for (pii &p : a[c]) {
			int s = p.fst, t = p.scd;
			if (imos[c][s + 1] < 0) {
				imos[c][s + 1]++;
			} else {
				imos[c][s]++;
			}
			imos[c][t + 1]--;
		}
	}

	rep(c, C) {
		for (int i = 1; i <= 100000; ++i) {
			imos[c][i] += imos[c][i - 1];
		}
	}

	int mx = 1;

	for (int i = 1; i <= 100000; ++i) {
		int sum = 0;
		rep(j, C) {
			sum += imos[j][i];
		}
		chmax(mx, sum);
	}


	cout << mx << endl;
}
