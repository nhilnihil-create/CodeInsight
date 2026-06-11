// ABC 126 E: 1 or 2
// https://atcoder.jp/contests/abc126/tasks/abc126_e

#include <iostream>
#include <vector>
#include <algorithm>
#define NIL -1
using intpair = std::pair<int,int>;

std::vector<std::vector<intpair>> adjacency_list;
std::vector<bool> node_stat;
std::vector<int> modulo_memo;

void SetNodeRelation(int vertex) {
    node_stat.at(vertex) = false;
    for (int i=0; i<adjacency_list.at(vertex).size(); i++) {
        int next_vertex = adjacency_list.at(vertex).at(i).first;
        int edge = (adjacency_list.at(vertex).at(i).second + modulo_memo.at(vertex)) % 2;
        modulo_memo.at(next_vertex) = edge;
        if (node_stat.at(next_vertex)) {
            SetNodeRelation(next_vertex);
        }
    }
}

int main() {
    int total_card_num, total_hint_num;
    std::cin >> total_card_num >> total_hint_num;
    adjacency_list.resize(total_card_num+1);
    node_stat.assign(total_card_num+1, true);
    modulo_memo.assign(total_card_num+1, NIL);
    for (int i=0; i<total_hint_num; i++) {
        int vertex, next_vertex, edge; std::cin >> vertex >> next_vertex >> edge;
        edge %= 2;
        adjacency_list.at(vertex).push_back(std::make_pair(next_vertex, edge));
        adjacency_list.at(next_vertex).push_back(std::make_pair(vertex, edge));
    }

    int count = 0;
    for (int i=1; i<adjacency_list.size(); i++) {
        if (node_stat.at(i)) {
            modulo_memo.at(i) = 0;
            SetNodeRelation(i);
            count++;
        }
    }
    std::cout << count << "\n"; 
}