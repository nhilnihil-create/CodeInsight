#include<iostream>
#include<iomanip>
#include<cassert>
#include<math.h>
#include<complex>
#include<algorithm>
#include<utility>
#include<queue>
#include<string.h>
#include<string>
#include<set>
#include<map>
#include<unordered_map>
#include<functional>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=2e18;
const ll MOD=1e9+7;

ll N,M;
ll indegree[100010];
vector<ll> edgeList[100010];
vector<ll> rEdgeList[100010];
ll order[100010];
int main(){
    cin>>N>>M;
	for(ll i=0;i<N-1+M;i++){
		ll a,b;cin>>a>>b;a--;b--;
		edgeList[a].push_back(b);
		rEdgeList[b].push_back(a);
		indegree[b]++;
	}
	ll nowOrder=0;
	queue<ll> q;
	for(ll i=0;i<N;i++) if(indegree[i]==0) q.push(i);
	while(!q.empty()){
		ll now=q.front();q.pop();
		order[now]=nowOrder;
		nowOrder++;
		for(auto v:edgeList[now]){
			indegree[v]--;
			if(indegree[v]==0) q.push(v);
		}
	}
	for(ll i=0;i<N;i++){
		ll parent;
		if(order[i]==0)parent=-1;
		ll nowMaxOrder=-1;
		for(auto v:rEdgeList[i]){
			if(nowMaxOrder<order[v]){
				parent=v;
				nowMaxOrder=order[v];
			}
		}
		cout<<parent+1<<endl;
	}
    return 0;
}