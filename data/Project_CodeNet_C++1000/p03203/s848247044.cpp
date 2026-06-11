#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>
#include<limits.h>
#include<cassert>
#include <fstream>
#include <time.h>
#include <iterator>


#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define REVERSE(v,n) reverse(v,v+n);
#define VREVERSE(v) reverse(v.begin(), v.end());
#define ll long long
#define pb(a) push_back(a)
#define m0(x) memset(x,0,sizeof(x))
#define print(x) cout<<x<<endl;
#define pe(x) cout<<x<<" ";
#define lb(v,n) lower_bound(v.begin(), v.end(), n);
#define ub(v,n) upper_bound(v.begin(), v.end(), n);
//#define int long long
#define all(x) (x).begin(), (x).end()

using namespace std;

const int MOD = (ll)1000000000 + 7;
const ll INF = 1e17;
const double pi = acos(-1);
const double EPS = 1e-10;
typedef pair<int, int>P;

int H, W, N;
vector<int>X[200020];
int bnd[200020];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> H >> W >> N;
	REP(i, N) {
		int x, y; cin >> x >> y;
		x--, y--;
		X[x].pb(y);
	}
	REP(i, H) {
		VSORT(X[i]);
	}
	int mx = 0;
	bnd[0] = 0;
	int cnt = 0;
	REP(i, H - 1) {
		if (binary_search(X[i + 1].begin(), X[i + 1].end(), mx)) {
			break;
		}
		else if (mx + 1 < W) {
			if (!binary_search(X[i + 1].begin(), X[i + 1].end(), mx + 1)) {
				mx++;
			}
			bnd[i + 1] = mx;
		}
		cnt++;
	}
	/*print(cnt);
	REP(i, cnt) {
		print(bnd[i]);
	}*/
	REP(i, H-1) {
		if (X[i + 1].size() == 0)continue;
		if (bnd[i] >= X[i + 1][0]) {
			print(i + 1);
			return 0;
		}
	}
	print(H); return 0;
}