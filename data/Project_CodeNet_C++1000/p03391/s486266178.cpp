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
#include<fstream>
#include<time.h>
#include<iterator>
#include<random>

//#pragma warning( disable:4996 )
using namespace std;

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

int MOD = (ll)1000000000 + 7;

const ll INF = 1e17;
const double pi = acos(-1);
const double EPS = 1e-10;
typedef pair<int, int>P;
const int MAX = 500050;

int A[200020], B[200020];

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int idx = 0, mx = 0,mn = INF;
	int N; cin >> N;
	bool found = false;
	REP(i, N) {
		cin >> A[i] >> B[i];
		if (A[i] > B[i]) {
			found = true;
			if (B[i] < mn) {
				mn = B[i];
				idx = i;
			}
		}
	}
	int ans = 0;
	if (!found) {
		print(0);
		return 0;
	}
	else {
		REP(i, N) {
			if (i == idx) {
				ans += A[i]-B[i];
			}
			else {
				ans += A[i];
			}
		}
	}
	print(ans);
}
