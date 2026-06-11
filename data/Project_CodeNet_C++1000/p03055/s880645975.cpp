#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include <numeric>
using namespace std;
#define INF (1 << 30) - 1
#define LINF 1LL << 60
const int MOD = 1000000007;
using ll = long long;
using P = pair<int, int>;

vector<vector<int>> g;

int max_dist = 0;
int max_v = -1;
void dfs(int v, int p = -1, int d = 0){
	if(d >= max_dist){
		max_dist = d;
		max_v = v;
	}
	for(auto nv : g[v]){
		if(nv == p)continue;
		dfs(nv, v, d + 1);
	}
}

int main(){
  int n;
  cin >> n;
  g.resize(n);
  for(int i = 0; i < n - 1; ++i){
  	int a, b;
  	cin >> a >> b;
  	--a;
  	--b;
  	g[a].push_back(b);
  	g[b].push_back(a);
  }

  dfs(0);
  dfs(max_v);
  if(max_dist % 3 == 1)cout << "Second" << endl;
  else cout << "First" << endl;

  return 0;
}
