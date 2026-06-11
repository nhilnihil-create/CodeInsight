#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

int n;
using p = std::pair<int, int>;
using Edmonds = std::vector<std::vector<int>>;

// 2部グラフの最大マッチングを利用

bool BipartiteMatching(Edmonds &G, int u, std::vector<bool> &seen, std::vector<int> &match){
    for(int v = 0; v < n; v++){
        if(G[u][v] && !seen[v]){
            seen[v] = true;
            if(match[v] < 0 || BipartiteMatching(G, match[v], seen, match)){
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int maxBM(Edmonds &G){
    std::vector<int> match(n, -1);
    
    int result = 0;
    for(int u = 0; u < n; u++){
        std::vector<bool> seen(n, false);

        if(BipartiteMatching(G, u, seen, match)) result++;
    }
    return result;
}

int main(){
    std::cin >> n;
    std::vector<p> red(n), blue(n);
    for(int i = 0; i < n; i++) std::cin >> red[i].first >> red[i].second;
    for(int i = 0; i < n; i++) std::cin >> blue[i].first >> blue[i].second;

    std::sort(red.begin(), red.end());
    std::sort(blue.begin(), blue.end());
    Edmonds bpGraph(n, std::vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        auto iter = std::lower_bound(blue.begin(), blue.end(), red[i]);
        for(;iter != blue.end(); iter++){
            if((*iter).second > red[i].second){
                int j = std::distance(blue.begin(), iter);
                bpGraph[i][j] = 1;
            }

        }
    }

    std::cout << maxBM(bpGraph) << std::endl;
    return 0;
}