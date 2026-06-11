#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

const int INF = 1e8;

int main() {
    int K, res;
    cin >> K;

    std::vector<bool> is_visited(K, false);

    std::deque<pair<int, int>> deq;

    deq.push_back(std::make_pair(1, 0));
    while(!deq.empty()) {
        auto v = deq.front();
        deq.pop_front();
        
        if(is_visited[v.first]) {
            continue;
        }

        is_visited[v.first] = true;

        if(v.first == 0) {
            res = v.second+1;
            break;
        }

        deq.push_front(std::make_pair((v.first*10)%K, v.second));
        deq.push_back(std::make_pair((v.first+1)%K, v.second+1));
    }

    std::cout << res << std::endl;
}