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

bool chmin(int&a,int b){return a>b?(a=b,true):false;}
bool chmax(int&a,int b){return a<b?(a=b,true):false;}
int read(){int a;scanf("%lld",&a);return a;}

vi S[1010];

signed main()
{
	int N; cin >> N;
 
	int a = -1;
	for (int i = 1; i <= 1000; ++i) {
		if (i * (i - 1) / 2 == N) {
			a = i;
			break;
		}
	}

	if (a == -1) {
		puts("No");
		return 0;
	}

	puts("Yes");
	printf("%lld\n", a);
 
	int id = 1;
	for (int i = 0; i < a; ++i) {
		for (int j = i + 1; j < a; ++j) {
			S[i].push_back(id);
			S[j].push_back(id);

			id++;
		}
	}

	for (int i = 0; i < a; ++i) {
		printf("%lld", (int)S[i].size());
		for (int j : S[i]) printf(" %lld", j);
		puts("");
	}
}

