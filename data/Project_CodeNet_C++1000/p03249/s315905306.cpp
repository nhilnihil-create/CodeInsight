#include <cstdio>
#include <algorithm>
#include <queue>
#include <map> 
#include <cstring>
using namespace std;
#define LL long long
const int N = 100010;
LL d[N];
queue<int>q;
int n;
int dist[N],sz[N];
map<LL,int>mp;
vector<int>g[N];
pair<int,int> edge[N];
int main(){
	scanf("%d",&n);
	for(register int i = 1;i <= n;++i){
		scanf("%lld",&d[i]);
		mp[d[i]] = i;
		sz[i] = 1;
	}
	for(register int i = 1;i < n;++i){
		auto it = mp.rbegin();
		int x = it -> second;
		LL dy = d[x] - n + 2*sz[x];
		if(mp.find(dy) == mp.end() || mp[dy] == x)
			return puts("-1"),0;
		int y = mp[dy];
		edge[i] = make_pair(x,y);
		g[x].push_back(y);
		g[y].push_back(x);
		sz[y] += sz[x];
		mp.erase(--mp.end());
	}
	memset(dist,-1,sizeof(dist));
	dist[1] = 0;
	LL tot = 0;
	q.push(1);
	while(q.size()){
		int x = q.front();
		tot += dist[x];
		q.pop();
		for(auto y : g[x])
		if(dist[y] == -1){
			dist[y] = dist[x] + 1;
			q.push(y);
		}
	}
	if(tot != d[1])
		return puts("-1"),0;
	for(int i = 1;i < n;++i)
		printf("%d %d\n",edge[i].first,edge[i].second);
	return 0;
}