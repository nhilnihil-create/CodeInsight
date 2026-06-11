#include <bits/stdc++.h>
#define INF (1<<30)
#define MOD 1000000007
#define l_ength size
using ll = long long;
using namespace std;

const int bound = 100010;

struct edge{
	int to;
	int cost;
};

vector<vector<edge>> graph(bound);
vector<int> dist(bound);

bool flag[bound];

int main(){
	fill( dist.begin(), dist.end(), INF );
	int k; cin >> k;
	for( int i = 1; i < k; ++i ){
		edge temp;
		temp.to = (i+1)%k; temp.cost = 1;
		graph[i%k].push_back(temp);
		temp.to = (i*10)%k; temp.cost = 0;
		graph[i%k].push_back(temp);
	}
	priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > q;
	q.emplace(1, 1);
	int ans = 0;
	int cnt = 0;
	while( cnt <= k && !q.empty() ){
		int s = q.top().first;
		int punkt = q.top().second;
		q.pop();
		if( flag[punkt] ) continue;
		++cnt;
		flag[punkt] = true;
		dist[(punkt)%k] = s;
		for( auto nextp : graph[punkt] ){
			if( dist[(nextp.to)%k] <= s+nextp.cost ) continue;
			q.emplace( s+nextp.cost, nextp.to );
		}	
	}
	cout << dist[0] << endl;
	return 0;
}