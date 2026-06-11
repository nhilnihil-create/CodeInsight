#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define RREP(i,a,b) for(int i=(a);i>=(b);i--)
#define pq priority_queue
#define P pair<ll,ll>
#define P2 pair<int,P>
#define P3 pair<int,P2>
typedef long long ll; typedef long double ld;
using namespace std;
const int INF=1e9, MOD=1e9+7, around[]={0,1,1,-1,-1,0,-1,1,0,0};
const ll LINF=1e18;
const ld PI=abs(acos(-1));
int k;
vector<P> g[100010];

ll dijkstra(int s, int t){
	ll min_cost[100010]={};
	pq<P, vector<P>, greater<P>> que;
	REP(i,0,k) min_cost[i]=INF;
	que.emplace(0,s);
	min_cost[s]=0;
	while(!que.empty()){
		auto p=que.top(); que.pop();
		if(p.first>min_cost[p.second]) continue;

		for(auto e:g[p.second]){
			if(p.first+e.second>=min_cost[e.first]) continue;
			min_cost[e.first]=p.first+e.second;
			que.emplace(min_cost[e.first], e.first);
		}
	}

	return min_cost[t];
}

int main(){
	cin >> k;
	REP(i,0,k) g[i].push_back(P((i*10)%k,0)),g[i].push_back(P((i+1)%k,1));
	
	cout << dijkstra(1,0)+1 << endl;
	return 0;
}
