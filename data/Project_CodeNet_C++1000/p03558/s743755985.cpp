#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long int;
using ull = unsigned long long int;

constexpr ll  k_max = 100000;

int main() {
    ll K;
    cin >> K;
    deque<ll> dq{};
    array<ll, k_max> costs{};
    costs.fill(numeric_limits<ll>::max());
    costs.at(1) = 1;
    constexpr ll initial_node = 1;

    dq.emplace_front(initial_node);
    while (!dq.empty()){
        ll node_from = dq.front();
        dq.pop_front();
        ll node_to;
        node_to = node_from * 10 % K;
        if (costs.at(node_to) > costs.at(node_from)){
            dq.push_front(node_to);
            costs.at(node_to) = costs.at(node_from);
        }
        node_to = (node_from+1) % K;
        if (costs.at(node_to) > costs.at(node_from)){
            dq.push_back(node_to);
            costs.at(node_to) = costs.at(node_from) + 1;
        }
    }
    cout << costs.at(0) << endl;
    return 0;
}