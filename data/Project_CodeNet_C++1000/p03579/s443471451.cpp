#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
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
ll INF = 1e17;
const double pi = acos(-1);
const double EPS = 1e-10;
const int MAX = 500050;
typedef pair<int, int>P;


vector<int>G[100010];
bool visited[100010];
int c[100010];
bool cir = false;
void dfs(int n, int pre,int cnt) {
	for (auto nex : G[n]) {
		if (nex == pre)continue;
		if (visited[nex]) {
			if (cnt%2 == c[nex]%2) {
				cir = true; return;
			}
		}
		else {
			c[nex] = cnt + 1;
			visited[nex] = true;
			dfs(nex, n, cnt + 1);
		}
		
	}
}

signed main() {
	int N, M; cin >> N >> M;
	REP(i, M) {
		int x, y; cin >> x >> y; x--, y--;
		G[x].pb(y); G[y].pb(x);
	}
	m0(visited);
	c[0] = 0;
	visited[0] = true;
	dfs(0, 0, 0);
	ll ans = 0;
	if (cir) {
		ans = N * (N - 1) / 2 - M;
	}
	else {
		int eve = 0, odd = 0;
		REP(i, N) {
			if (c[i] % 2 == 0)eve++; else odd++;
		}
		ans = eve * odd - M;
	}
	print(ans);
}