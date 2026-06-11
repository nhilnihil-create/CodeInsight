#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX

int n, m;
vector<pair<int, int> > graph[100010];

int cost[100010];

bool flag = true;

void dfs(int idx, int num){
    if(!flag) return;

    cost[idx] = num;
    for(int i = 0;i < graph[idx].size();i++){
        if(cost[graph[idx][i].first] != INF){
            if(cost[graph[idx][i].first] != num + graph[idx][i].second){
                flag = false;
                return;
            }
        }else{
            dfs(graph[idx][i].first, num+graph[idx][i].second);
        }
    }
    return;
}

int main(){
    cin >> n >> m;
    int a, b, c;
    for(int i = 0;i < m;i++){
        cin >> a >> b >> c;
        a--, b--;
        graph[a].push_back(make_pair(b, c));
        graph[b].push_back(make_pair(a, -c));
    }

    for(int i = 0;i < n;i++){
        cost[i] = INF;
    }

    for(int i = 0;i < n;i++){
        if(cost[i] == INF){
            dfs(i, 0);
        }
    }

    if(flag){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}

