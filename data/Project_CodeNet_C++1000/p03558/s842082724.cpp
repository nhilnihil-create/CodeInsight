#include <bits/stdc++.h>
using namespace std;
#define REP(i,x,n) for(int i = x; i < n; i++)
#define MAX 100
#define INF 1000000001

int k;
// int a[2000];

// char X[100][100];
// int dp[1000000001];
vector<pair<int,int>> adj[114514];
long long dis[114514];
bool processed[114514];

void dijkstra() {
    priority_queue<pair<int,int>> q; // q({-d,x})
    
    REP(i,0,114514) dis[i] = INF;
    dis[1] = 0;
    q.push({0,1});
    
    while(!q.empty()) {
        int a = q.top().second; q.pop();
        if (processed[a]) continue;
        processed[a] = true;
        for (auto u : adj[a]) {
            int b = u.first, w = u.second;
            if (dis[a] + w < dis[b]) {
                dis[b] = dis[a] + w;
                q.push({-dis[b],b});
            }
        }
    }
    
    return;
}

int main(void){
    // a[0] = 100;
    // a[2] = 2;
    // fill(a,a+3,100);
    // cout << count(a,a+3,100) << endl;
    cin >> k;
   
    
    REP(i,0,k) {
        adj[i].push_back({(i+1)%k,1});
    }
    
    REP(i,0,k) {
        adj[i].push_back({(i*10%k),0});
    }
    
    dijkstra();
    cout << dis[0] + 1 << endl;

}