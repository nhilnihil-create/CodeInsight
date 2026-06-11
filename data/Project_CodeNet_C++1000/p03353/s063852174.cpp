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

const int INF = 1e9 + 7;

signed main()
{
	string s; cin >> s;
	int n = s.size();
	int k; cin >> k;

	vector<string> A;

	rep(i, n) {
		string t = "";
		rep(j, min(k, 5ll)) {
			if (i + j < n) {
				t += s[i + j];
				A.PB(t);
			}
		}
	}

	sort(all(A));
	unique(all(A));

	cout << A[k - 1] << endl;
}
