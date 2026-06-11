#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;

int N;
vector<vector<int>> G;
vector<int> c;
vector<int> ans;
int cnt = 0;

void dfs(int u, int p){
	ans[u] = c[cnt];
	cnt++;
	for(int v : G[u]){
		if(v == p) continue;
		dfs(v,u);
	}
}

int main(){
	cin >> N;
	G.resize(N);
	ans.resize(N);
	rep(i,N-1){
		int a,b; cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	c.resize(N);
	rep(i,N) cin >> c[i];
	sort(c.begin(),c.end(),greater<int>());
	dfs(0,-1);
	ll sum = 0;
	repr(i,1,N) sum += c[i];
	cout << sum << endl;
	rep(i,N){
		if(i) cout << " ";
		cout << ans[i];
	}
	cout << endl;

}

