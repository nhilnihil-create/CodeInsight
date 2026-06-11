#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Edge {
    int to;
    int weight;
    Edge(int t, int w) : to(t), weight(w) { }
};
using Graph = vector<vector<Edge>>;

int main(){
    ll n;
    cin >> n;
    Graph G(n);
    for(ll i=0;i<n-1;i++){
        ll from,to,weight;
        cin >> from >> to >> weight;
        from--;
        to--;
        G[from].push_back(Edge(to, weight));
        G[to].push_back(Edge(from, weight));
    }
    vector<ll> color(n,-1);
	queue<ll> que;
	color[0]=0;
	que.push(0);
	while(!que.empty()){
        auto v=que.front();
        que.pop();
        for(auto nv:G[v]){
            if(color[nv.to]!=-1) continue;
            else{
                que.push(nv.to);
                if(nv.weight%2==0) color[nv.to]=color[v];
                else color[nv.to]=1-color[v];
            }
        }
    }
    for(ll i=0;i<n;i++){
        cout << color[i] << endl;
    }
}
