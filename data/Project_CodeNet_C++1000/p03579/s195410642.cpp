
#include<iostream>
#include<cstdio>
#include<cstring>
#include <cstdlib>  
#include <cmath>   
#include<cctype>
#include<string>
#include<set>
#include <map>
#include<algorithm>
#include <functional>
#include<vector>
#include<climits>
#include<stack>
#include<queue>
#include <deque>
#include <climits>
#include <typeinfo>
#include <utility> 
#define all(x) (x).begin(),(x).end()
#define rep(i,m,n) for(int i = m;i < n;++i)
#define pb push_back
#define rrep(i,m,n) for(int i = m;i >= n;--i)
#define INF INT_MAX-1;
using namespace std;
using ll = long long;
using R = double;
const ll inf = 1LL << 50;
const ll MOD = 1e9 + 7;
struct edge { ll from; ll to; ll cost; };

vector<ll>G[101010];
ll V;
ll color[101010];

bool dfs(ll v, ll c) {
	color[v] = c;
	rep(i, 0, G[v].size()) {
		if (color[G[v][i]] == c)return false;
		if (color[G[v][i]] == 0 && !dfs(G[v][i],-c))return false;
	}
	return true;
}

int main(){
	cin >> V;
	ll m;
	cin >> m;
	rep(i, 0, m) {
		ll a, b;
		cin >> a >> b;
		a--; b--;
		G[a].pb(b);
		G[b].pb(a);
	}
	bool check = dfs(0, 1);
	if (!check) {
		cout << V * (V - 1) / 2 - m << endl;
	}
	else if(check){
		ll bl = 0;
		ll wh = 0;
		rep(i, 0, 101010) {
			if (color[i] == 1)bl++;
			else if (color[i] == -1)wh++;
		}
		cout << bl * wh - m << endl;
	}

	return 0;
}