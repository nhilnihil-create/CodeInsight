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
#include <fstream>


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
#define int long long
#define all(x) (x).begin(), (x).end()

using namespace std;

const int MAX = 1010000;
const int MOD = (ll)1000000000 + 7;
const ll INF = 1e17;
const double pi = acos(-1);
const double EPS = 1e-10;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0, };
typedef pair<int, int>P;

int N, K, Q;
vector<int>A;

signed main() {
	//std::ifstream in("test2.txt");
	//std::cin.rdbuf(in.rdbuf());
	cin >> N >> K >> Q;
	A.resize(N);
	REP(i, N)cin >> A[i];
	A.pb(-INF); A.pb(-INF);
	int l = 0, r = 0;
	int ans = INF;
	REP(i, N) {
		vector<int>res;
		int x = A[i];
		l = 0, r = 0;
		while (r < N) {
			if (A[l] < x) {
				l++; r++;
				continue;
			}
			if (A[r + 1] >= x) {
				r++;
			}
			else {
				if (r - l + 1 >= K) {

					vector<int>vec;
					for (int j = l; j <= r; j++) {
						vec.pb(A[j]);
					}
					VSORT(vec);
					REP(k, r - l + 2 - K) {
						res.pb(vec[k]);
					}
				}
				l = r + 2;
				r += 2;
			}
		}
		if (res.size() == 0)continue;
		VSORT(res);
		if (res[0] < x) {
			//print("fault");
			//return 0;
		}
		if (res.size() >= Q) {
			//print(res[Q - 1] - res[0]);
			ans = min(ans, res[Q - 1] - res[0]);
		}
	}
	print(ans);
}
