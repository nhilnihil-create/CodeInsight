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

using ll=long long;
using vi=vector<int>;
using pii=pair<int, int>;

bool chmin(int&a,int b){return a>b?(a=b,true):false;}
bool chmax(int&a,int b){return a<b?(a=b,true):false;}
int read(){int a;scanf("%lld",&a);return a;}

const int inf = 1e9 + 10;

int N;
int F[101][5][2];
int P[101][11];
int c[100];

signed main()
{
	cin >> N;
	rep(i, N) {
		rep(j, 5) {
			rep(k, 2) {
				cin >> F[i][j][k];
			}
		}
	}

	rep(i, N) rep(j, 11) cin >> P[i][j];

	int mx = -inf;

	for (int S = 1; S < (1 << 10); ++S) {
		memset(c, 0, sizeof c);
		int score = 0;

		rep(i, 10) {
			if (S >> i & 1) {
				rep(j, N) {
					c[j] += F[j][i / 2][i % 2];
				}
			}
		}

		rep(i, N) score += P[i][c[i]];

		chmax(mx, score);
	}

	cout << mx << endl;
}

