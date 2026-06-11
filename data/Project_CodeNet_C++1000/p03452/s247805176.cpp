#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const ull mod = 1e9 + 7;
#define REP(i,n) for(int i=0;i<(int)n;++i)
const ll MAX_N = 100005; 

vector<pll> infos[MAX_N];
vector<ll> place(MAX_N);
vector<bool> visited(MAX_N);

bool dfs(int now){
	visited[now] = true;
	REP(i, infos[now].size()){
		int next = infos[now][i].first;
		if (visited[next]){
			if(place[next] != place[now] + infos[now][i].second){
				return false;
			}
		}else{
			place[next] = place[now] + infos[now][i].second;
			if (!dfs(next)) return false;
		}
	}
	return true;
}

int main(){
	ll N, M;
	cin >> N >> M;
	REP(i, M){
		ll l, r, d;
		cin >> l >> r >> d;
		l--;r--;
		infos[l].push_back(make_pair(r, d));
		infos[r].push_back(make_pair(l, -d));
	}
	REP(i, N) place[i] = -1;
	REP(i, N) visited[i] = false;

	bool flag = true;
	REP(i, N){
		if(visited[i]==true) continue;
		visited[i] = 0;
		if(!dfs(i)) flag = false;
	}
	cout << (flag ? "Yes" : "No") << endl;
    return 0;
}