// ABC 126 D: Even Relation
// https://atcoder.jp/contests/abc126/tasks/abc126_d

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1000000000+7
using intpair = std::pair<int,int>;

std::vector<std::vector<intpair>> adjacency_list;
std::vector<bool> node_stat;
std::vector<int> isEven;

void paint(int vertex) {
    node_stat.at(vertex) = false;
    for (int i=0; i<adjacency_list.at(vertex).size(); i++) {
        int next_vertex = adjacency_list.at(vertex).at(i).first;
        int edge_weight = (adjacency_list.at(vertex).at(i).second + isEven.at(vertex)) % 2;
        isEven.at(next_vertex) = edge_weight;
        if (node_stat.at(next_vertex)) {
            paint(next_vertex);
        } else {}
    }
}

int main() {
    int total_node_num; std::cin >> total_node_num;
    adjacency_list.resize(total_node_num+1);
    node_stat.assign(total_node_num+1, true);
    isEven.assign(total_node_num+1, INF);
    int vertex, next_vertex, edge_weight;
    while (std::cin >> vertex >> next_vertex >> edge_weight) {
        edge_weight = edge_weight % 2;
        adjacency_list.at(vertex).push_back(std::make_pair(next_vertex, edge_weight));
        adjacency_list.at(next_vertex).push_back(std::make_pair(vertex, edge_weight));
    }

    for (int i=1; i<node_stat.size(); i++) {
        if (node_stat.at(i)) {
            isEven.at(i) = 0;
            paint(i);
        }
    }

    for (int i=1; i<isEven.size(); i++) {
        std::cout << isEven.at(i) << "\n";
    }
}