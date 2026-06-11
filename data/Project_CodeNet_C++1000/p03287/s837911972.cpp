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

int N, M;
int A[100010];
int sum[100010];
map<int, int> m;

signed main()
{
	cin >> N >> M;
	int ans = 0;
	m[0]++;
	rep1(i, N) {
		cin >> A[i];
		sum[i] = A[i] + sum[i - 1];
		sum[i] %= M;
		ans += m[sum[i]];
		m[sum[i]]++;
	}

	cout << ans << endl;
}
// sum[i] = sum[j] (mod M) ( i > j )
