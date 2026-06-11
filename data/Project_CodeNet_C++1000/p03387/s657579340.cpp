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
#include <unordered_map>

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
//int read(){int a;scanf("%lld",&a);return a;}

constexpr int TEN(int n){return n==0?1:10*TEN(n-1);}

const int inf = TEN(18)*3 + 10;
const int mod = TEN(9) + 7;

int N, K;
int rui[100010], rui_b[100010];

signed main()
{
	int a,b,c;cin >> a >> b >> c;
	int m = max(a, max(b, c));

	for(;;m++){
		int s=3*m-(a+b+c);
		if (s % 2 == 0) {
			cout << s / 2 << endl;
			return 0;
		}
	}
}

