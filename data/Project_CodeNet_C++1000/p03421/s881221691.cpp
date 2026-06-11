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
#include<random>



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

int MOD = (ll)1000000000 + 7;
const ll INF = 1e17;
const double pi = acos(-1);
const double EPS = 1e-10;
typedef pair<int, int>P;
const int MAX = 500050;


int N, A, B;
vector<int>v[300030];
set<int>st;
map<int, int>mp;
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	bool debug = 0;
	cin >> N >> A >> B;
	if (N<(A + B - 1) || N>A*B) {
		print(-1); return 0;
	}
	//ーーー構築ーーー
	REP(i, A) {
		v[0].pb(i + A * B - A + 1);
	}
	FOR(i, 1, B) {
		v[i].pb(A*B - A * i - A + 1);
	}
	int nw = A + B - 1;
	int rem = N - nw;
	FOR(i, 1, B) {
		FOR(j, 1, A) {
			if (rem == 0)goto END;
			v[i].pb(A*B - A * i - A + 1 + j);
			rem--;
		}
	}
END:;
	//ーーー構築ーーー

	if (debug) {
		REP(i, B) {
			REP(j, v[i].size()) {
				pe(v[i][j]);
			}cout << endl;
		}
		cout << endl;
	}

	//ーーー座圧ーーー
	REP(i, B) {
		REP(j, v[i].size()) {
			st.insert(v[i][j]);
		}
	}
	int c = 1;
	for (auto x : st) {
		mp[x] = c;
		c++;
	}
	//ーーー座圧ーーー

	REP(i, B) {
		REP(j, v[i].size()) {
			pe(mp[v[i][j]]);
		}
		//cout << endl;
	}
	cout << endl;
}