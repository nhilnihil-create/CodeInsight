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


string S;
bool check(string S) {
	int n = S.size();

	if (S[1] == '0' || S[n - 2] == '0')return false;
	REP(i, n) {
		if (S[i] != S[n - i-1]) {
			return false;
		}
	}
	return true;
}
vector<int>G[100010];
vector<int>v;
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> S;
	S = "0" + S;

	int N = S.size();
	if (!check(S)) {
		print(-1); return 0;
	}
	
	REP(i, N) {
		if (S[i] == '1') {
			v.pb(i);
		}
	}
	int M = v.size();
	REP(i, M) {
		G[i].pb(i + 1);
	}
	int cnt = 1, nx = M + 1;
	REP(i, M) {
		int cnt2 = 0;
		REP(j, v[i] - cnt) {
			G[i].pb(nx);
			nx++, cnt2++;
		}
		cnt += cnt2;
		cnt++;
	}
	REP(i, N + 1) {
		for (auto x : G[i]) {
			pe(i + 1)print(x + 1);
		}
	}
}