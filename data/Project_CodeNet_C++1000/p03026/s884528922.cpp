#include <iostream>
#include <iomanip>
#include <utility>
#include <cmath>
#include <random>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

#define rep(i,n) for(int i = 0; i<n; ++i)
#define REP(i,n) for(int i = 1; i<=n; ++i)
#define all(x) begin(x),end(x)
#define show(obj) {for(auto x:obj)cout<<x<<' ';cout<<endl;}
#define line "----------"
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> LP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
	int N, a, b; cin >> N;
	vector<int> costs(N);
	vector<vector<int>> G(N, vector<int>());
	rep(i,N-1){
		cin >> a >> b;
		--a; --b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	ll max_score = 0;
	rep(i,N){
		cin >> costs[i];
		max_score += costs[i];
	}
	sort(all(costs), greater<int>());
	max_score -= costs[0];
	int use = 0;
	vector<int> ans(N, inf);
	queue<int> Q;
	Q.push(0);
	ans[0] = costs[use++];
	while(!Q.empty()){
		int f = Q.front();
		Q.pop();
		for(auto x:G[f]){
			if(ans[x] == inf){
				ans[x] = costs[use++];
				Q.push(x);
			}
		}
	}
	cout << max_score << endl;
	show(ans);
		return 0;
}
