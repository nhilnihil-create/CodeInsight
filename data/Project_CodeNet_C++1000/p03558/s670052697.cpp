#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<deque>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define P pair<int, int>

struct edge{int to, cost;};

int main(){
    int k;
    cin >> k;
    vector<edge> G[k];
    rep(i, k){
        edge g;
        g.to = (i + 1) % k;
        g.cost = 1;
        G[i].push_back(g);
        g.to = (i * 10) % k;
        g.cost = 0;
        G[i].push_back(g);
    }
    // rep(i, k){
    //     rep(j, G[i].size()){
    //         cout << G[i][j].to << ":" <<G[i][j].cost << " ";
    //     }
    //     cout << endl;
    // }
    deque<P> q;
    q.push_back(P(1, 1));
    int d[k];
    rep(i, k) d[i] = -1;
    while(q.size() > 0){
        P p = q.front();
        q.pop_front();
        int t = p.first;
        int c = p.second;
        if(d[t] != -1) continue;
        d[t] = c;
        for (int i = 0; i < G[t].size(); i++){
            if(d[G[t][i].to] != -1) continue;
            if (G[t][i].cost == 0){
                q.push_front(P(G[t][i].to, c));
            }else{
                q.push_back(P(G[t][i].to, c + 1));
            }
        }
    }
    cout << d[0] << endl;
}