#include <bits/stdc++.h>
#define ALL(A) (A).begin(),(A).end()
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)

const ll mod = 1e9+7;
const ll INF = -1*((1LL<<63)+1);
const int inf = -1*((1<<31)+1);

using namespace std;

bool v[100005];

void dfs(int now,vector<vector<int>> &to,vector<vector<int>> &cost,vector<int> &d){
	if(v[now] == 0 ){
		v[now] = 1;
		d[now] = 0;
	}
	for(int i=0;i<to[now].size();i++){
		int next = to[now][i];
		if(v[next]==1)continue;
		d[next] = d[now] + cost[now][i];
		v[next] = 1;
		dfs(next,to,cost,d);
	}
}
int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N,M;
	cin >> N >> M;
	vector<vector<int>> to(N),cost(N);
	vector<int> d(N),L(M),R(M),D(M);
	rep(i,M){
		int a,b,c;
		cin >> a >> b >> c;
		a--;
		b--;
		L[i] = a;
		R[i] = b;
		D[i] = c;
		to[a].push_back(b);
		cost[a].push_back(c);
		to[b].push_back(a);
		cost[b].push_back(-c);
	}
	rep(i,N){
		dfs(i,to,cost,d);
	}
	rep(i,M){
		if(d[R[i]] - d[L[i]] != D[i]){
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
}