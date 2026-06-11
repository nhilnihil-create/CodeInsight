#include <iostream>
#include <vector>

#define MAX_V 100010
using namespace std;

struct edge{long long to,cost; };
vector<edge> G[MAX_V];

bool used[MAX_V];
int l[200010],r[200010];
long long d[MAX_V],k[200010];
int V,E;

void dfs(int s){
	used[s] = true;
	int i = 0;
	while(true){
		edge e = G[s][i];
		if(e.to==-1){
			break;
		}
		i++;
		if(!used[e.to]){
			used[e.to] = true;
			d[e.to] = d[s]+e.cost;
			dfs(e.to);
		}
	}
}

int main(){
	int i;
	cin >> V >> E;
	for(i=0;i<E;i++){
		cin >> l[i] >> r[i] >> k[i];
		l[i]--; r[i]--;
		edge e;
		e.to = r[i];
		e.cost = k[i];
		G[l[i]].push_back(e);
		e.to = l[i];
		e.cost = -k[i];
		G[r[i]].push_back(e);
		}
	for(i=0;i<V;i++){
		edge e;
		e.to = -1; e.cost = 0;
		G[i].push_back(e);
		used[i] = false;
	}
	
	for(i=0;i<V;i++){
        if(!used[i]){
            d[i] = 0;
            dfs(i);
        }
	}
	
	for(i=0;i<E;i++){
		if(k[i]==d[r[i]]-d[l[i]]){
			continue;
		}
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
}