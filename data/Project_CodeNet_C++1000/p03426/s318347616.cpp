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

int H, W, D;

int A[305][305];
int sum[300*300 + 10];
pii pos[300*300 + 10];

int distance(pii p, pii q)
{
	return abs(p.fst - q.fst) + abs(p.scd - q.scd);
}

signed main()
{
	cin >> H >> W >> D;

	rep(i, H) rep(j, W) {
		A[i][j] = read();
		pos[A[i][j]] = pii(i, j);
	}

	rep1(i, D) {
		int start = i;
		pii cur = pos[start];

		while (start <= H * W) {
			if (start - D > 0) {
				sum[start] = sum[start - D] + distance(pos[start - D], pos[start]);
			}

			cur = pos[start + D];
			start += D;
		}
	}

	int Q; cin >> Q;

	rep(_, Q) {
		int l = read(), r = read();

		printf("%lld\n", sum[r] - sum[l]);
	}
}


