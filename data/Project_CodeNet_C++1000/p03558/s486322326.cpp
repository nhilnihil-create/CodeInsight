#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(a) a.begin(), a.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;

// AtCoder Grand Contest 037
int main(){

    int K;
    cin >> K;
    
    typedef pair<int, int> edge;
    #define to first
    #define cost second

    vector<vector<edge>> graph(K);
    rep(i, K){
        if(i % 10 != 9)graph[i].push_back(edge((i + 1) % K, 1));
        graph[i].push_back(edge((i * 10) % K, 0));
    }

    const int inf = 1000000000;
    vector<int> dist(K, inf);
    deque<int> deq;
    dist[1] = 1; deq.push_back(1);

    while(deq.size()){
        int v = deq.front();
        deq.pop_front();
        for(edge e : graph[v]){
            if(chmin(dist[e.to], dist[v] + e.cost)){
                if(e.cost == 0)deq.push_front(e.to);
                else deq.push_back(e.to);
            }
        }
    }

    cout << dist[0] << endl;
    return 0;

}