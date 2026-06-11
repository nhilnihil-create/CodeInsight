#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;
vector<vector<int>> g(10005);
vector<int> c;
vector<int> ans(10005);

ll dfs(int x,int parent){
	ll res = 0LL;
	for(int i = 0; i < g[x].size(); i++) {
		if (g[x][i] != parent){
			res += dfs(g[x][i],x);
			res += min(ans[x],ans[g[x][i]]);
		}
	}
	return res;
}


int main(){
	int n;cin>>n;
	for(int i = 0; i < n - 1; i++) {
		int a,b;cin>>a>>b;
		g[a].pb(b);
		g[b].pb(a);
	}
	for(int i = 0; i < n; i++) {
		int l;cin>>l;
		c.pb(l);
	}
	sort(ALL(c),greater<int>());

	queue<int> q;
	q.push(1);
	int cnt = 0;
	int parent = 0;
	vector<bool> used(n + 1,false);
	while(!(q.empty())){
		int top = q.front();
		ans[top] = c[cnt];
		used[top] = true;
		cnt++;
		q.pop();
		for(int i = 0; i < g[top].size(); i++) {
			if (!(used[g[top][i]])){
				q.push(g[top][i]);
			}
		}
	}

	cout << dfs(1,0) << endl;
	for(int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}