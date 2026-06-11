#include<iostream>
#include<vector>
#include<string>
#include<queue>
int n, m;
std::vector<std::vector<bool>> graph;

bool bfs(){
    std::vector<bool> state(n, false);
    std::queue<int> que;

    int now = 0;
    que.push(now);

    while(!que.empty()){
        now = que.front(); que.pop();
        state[now] = true;

        for(int i = 0; i < n; i++){
            if(graph[now][i] && !state[i]){
                que.push(i);
            }
        }
    }

    // check
    for(int i = 0; i < n; i++){
        if(state[i] == false) return true; // 橋です
    }

    return false; // 橋でない
}

int main(){
    std::cin >> n >> m;
    graph.resize(n, std::vector<bool>(n, false));
    std::vector<int> edge1(m);
    std::vector<int> edge2(m);
    for(int i = 0; i < m; i++){
        int a, b;
        std::cin >> a >> b;
        a--; b--;
        edge1[i] = a;
        edge2[i] = b;
        graph[a][b] = true;
        graph[b][a] = true;
    }

    int cnt = 0;
    for(int i = 0; i < m; i++){
        int a = edge1[i], b = edge2[i];
        graph[a][b] = false;
        graph[b][a] = false;
        if(bfs()) cnt++;
        graph[a][b] = true;
        graph[b][a] = true;
    }

    std::cout << cnt << std::endl;
    return 0;
}
