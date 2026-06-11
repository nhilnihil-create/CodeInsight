#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const long long INF = 1LL<<60;

int main() {
    int V=10;
    int E=10;
    int H,W;
    cin >> H >> W;
    // initialization of Floyd-Warshall
    vector<vector<long long> > dp(V, vector<long long>(V, INF));
    for (int i = 0; i < V; ++i) dp[i][i] = 0;  // necessary
    
    // input
    for(int v=0;v<V;++v){
      for (int e=0;e<E;++e) {
        int w;
        cin >> w;
        dp[v][e] = w;
      }
    }
    // Floyd-Warshall
    for (int k = 0; k < V; ++k)
        for (int i = 0; i < V; ++i)
            for (int j = 0; j < V; ++j)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
    
    // output
    long long sum=0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            int w;
            cin >> w;
            if(w<0);
            else sum+= max(dp[w][1],0LL);
        }
    }
    cout << sum << endl;
}