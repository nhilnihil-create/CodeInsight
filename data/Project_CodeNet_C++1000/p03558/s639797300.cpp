#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define RREP(i,a,b) for(int i=(a);i>=(b);i--)
#define pq priority_queue
#define P pair<int,int>
#define P2 pair<int,P>
#define P3 pair<int,P2>
typedef long long ll; typedef long double ld;
using namespace std;
const int INF=1e9, MOD=1e9+7, around[]={0,1,1,-1,-1,0,-1,1,0,0};
const ll LINF=1e18;
const ld PI=abs(acos(-1));

vector<P> g[100010];
int n;

int solve(){
	int min_cost[100010]; REP(i,0,n) min_cost[i] = INF;
	deque<P> qu; qu.push_front({1,1}); min_cost[1] = 0;
	
	while(!qu.empty()){
		auto p = qu.front(); qu.pop_front();
		
		for(auto e:g[p.second]){
			if(p.first + e.second >= min_cost[e.first]) continue;
			min_cost[e.first] = p.first + e.second;
			
			if(e.second) qu.push_back({min_cost[e.first], e.first});
			else qu.push_front({min_cost[e.first], e.first});
		}
	}
	
	return min_cost[0];
}

int main(){
	cin >> n;
	
	REP(i,0,n){
		g[i].push_back({(i+1)%n, 1});
		g[i].push_back({(i*10)%n, 0});
	}
	
	cout << solve() << endl;
	return 0;
}
