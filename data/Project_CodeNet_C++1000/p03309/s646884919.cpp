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

int N;

signed main()
{
	cin >> N;

	vector<int> a(N);
	rep(i, N) {
		cin >> a[i];
		a[i] -= i + 1;
	}

	sort(all(a));

	int mid = N % 2 == 0 ? (a[N / 2 - 1] + a[N / 2]) / 2 : a[N / 2];

	int ans = 0;
	rep(i, N) ans += abs(mid - a[i]);

	cout << ans << endl;
}

