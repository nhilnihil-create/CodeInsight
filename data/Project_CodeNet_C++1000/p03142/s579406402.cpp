
#include<iostream>
#include<cstdio>
#include<cstring>
#include <cstdlib>  
#include <math.h>
#include <cmath>
#include<cctype>
#include<string>
#include<set>
#include<iomanip>
#include <map>
#include<algorithm>
#include <functional>
#include<vector>
#include<climits>
#include<stack>
#include<queue>
#include<bitset>
#include <deque>
#include <climits>
#include <typeinfo>
#include <utility> 
using namespace std;
using ll = long long;
using R = double;
using Data = pair < ll, vector <ll>>;
const ll MOD = 1e9 + 7;
const ll inf = 1LL << 60;
struct edge { ll from; ll to; ll cost; };
typedef tuple<ll, ll, ll>T;
typedef pair<ll, ll>pll;
#define all(x) (x).begin(),(x).end()
#define rep(i,m,n) for(ll i = m;i < n;++i)
#define pb push_back
#define fore(i,a) for(auto &i:a)
#define rrep(i,m,n) for(ll i = m;i >= n;--i)
#define INF INT_MAX/2

vector<int>pa[101010];
vector<int>e[101010];
vector<int>ans(101010,-1);

void dfs(int n) {
	fore(x,e[n]) {
		if (ans[x] != -1)continue;
		int ok = 1;
		fore(y, pa[x]) {
			if (ans[y] == -1) {
				ok = 0;
				break;
			}
		}
		if (ok) {
			ans[x] = n+1;
			dfs(x);
		}
	}
}


int main() {
	int n, m;
	cin >> n >> m;

	rep(i, 0, n + m - 1) {
		int a, b;
		cin >> a >> b;

		a--, b--;
		pa[b].pb(a);
		e[a].pb(b);
	}

	rep(i, 0, n) {
		if (pa[i].size() == 0) {
			ans[i] = 0;
			dfs(i);
			break;
		}
	}

	rep(i, 0, n) {
		cout << ans[i] << endl;
	}

	return 0;
}