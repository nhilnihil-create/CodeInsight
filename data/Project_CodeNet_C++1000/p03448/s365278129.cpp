#include "bits/stdc++.h"

#define REP(i,n) for(int i=0;i< (n);i++)
#define REPR(i, n) for(int i = (n);i >= 0;i--)
#define FOR(i, m, n) for(int i = (m);i < (n);i++)
#define FORR(i, m, n) for(int i = (m);i >= (n);i--)
#define SORT(v, n) std::sort(v, v+n);
#define VSORT(v) std::sort(v.begin(), v.end());
#define VRSORT(v) std::sort(v.rbegin(), v.rend());
#define ll long long
#define pb(a) push_back(a)
#define ALL(obj) (obj).begin(),(obj).end()

using namespace std;

const int INF = 99999999;
const ll LINF = 9999999999999;

typedef pair<int, int> P;
typedef pair<ll, ll> LP;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };


ll a, b, c, x;
ll num = 0;
int main() {
	cin >> a >> b >> c >> x;
	REP(i, a+1) {
		REP(j, b+1) {
			REP(k, c+1) {
				if (500 * i + 100 * j + 50 * k == x) num++;
			}
		}
	}

	cout << num << endl;

	return 0;
}