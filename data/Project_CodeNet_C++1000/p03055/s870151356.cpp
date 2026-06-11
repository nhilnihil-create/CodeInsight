#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#define llint long long
//#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define printP(x) "(" << (x).first << ", " << (x).second << ")"
#define mod 1000000007
using namespace std;
typedef pair<int, int> P;

llint n;
vector<llint> G[200005];

llint dtmp[200005];
llint distdfs(vector<llint> G[], int v, int p, llint d)
{
	dtmp[v] = d;
	for(int i = 0; i < G[v].size(); i++){
		llint u = G[v][i], c = 1; //
		if(u == p) continue;
		distdfs(G, u, v, d+c);
	}
}

llint getDiameter(vector<llint> G[], llint n, llint &u, llint &v)
{
	distdfs(G, 1, -1, 0);
	llint max_val = -1, max_v;
	for(int i = 1; i <= n; i++){
		if(max_val < dtmp[i]){
			max_val = dtmp[i];
			max_v = i;
		}
	}
	u = max_v;
	
	distdfs(G, u, -1, 0);
	max_val = -1;
	for(int i = 1; i <= n; i++){
		if(max_val < dtmp[i]){
			max_val = dtmp[i];
			max_v = i;
		}
	}
	v = max_v;
	
	return max_val;
}

int main(void)
{
	cin >> n;
	llint u, v;
	for(int i = 1; i <= n-1; i++){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	llint d = getDiameter(G, n, u, v);
	
	if(d % 3 == 1) cout << "Second" << endl;
	else cout << "First" << endl;
	
	return 0;
}
