#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <utility>

using P = std::pair<int, long long>;

class Edge{
public:
    int from, to;
    long long cost;
    Edge(): from(0), to(0), cost(0){}
    Edge(int u, int v, long long w): from(u), to(v), cost(w){}
    ~Edge(){}
    bool operator<(const Edge &e)const{
        return cost < e.cost;
    }
};

void search(std::vector<long long> &dist,
    std::vector<bool> &visited,
    std::vector<std::list<P> > &e_list, int s)
{
    std::deque<P> que;
    que.push_front(P(s, 0));
    while(!que.empty()){
        int u = que.back().first;
        long long d = que.back().second;
        que.pop_back();
        if(visited[u] == true) continue;

        visited[u] = true;
        dist[u] = d;
        for(auto &&itr = e_list[u].begin(); itr != e_list[u].end(); itr++){
            int v = itr->first;
            long long c = itr->second;
            que.push_front(P(v, d+c));
        }
    }
}

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    std::vector<Edge> edge(M);
    for(int i=0; i<M; i++){
        scanf(" %d %d %lld", &edge[i].from, &edge[i].to, &edge[i].cost);
        edge[i].from--; edge[i].to--;
    }

    if(M == 0){
        std::cout << "Yes" << std::endl; return 0;
    }

    std::vector<std::list<P> > e_list(N);
    for(int i=0; i<M; i++){
        int u = edge[i].from;
        int v = edge[i].to;
        int c = edge[i].cost;
        e_list[u].push_back(P(v, c));
        e_list[v].push_back(P(u, -c));
    }

    std::vector<long long> dist(N);
    std::vector<bool> visited(N, false);
    for(int i=0; i<N; i++){
        if(visited[i] == false) search(dist, visited, e_list, i);
    }

    bool flag = true;
    for(int i=0; i<M; i++){
        int u = edge[i].from;
        int v = edge[i].to;
        int d = edge[i].cost;
        if(dist[v] - dist[u] != d) flag = false;
    }

    if(flag == true) std::cout << "Yes" << std::endl;
    else std::cout << "No" << std::endl;
}