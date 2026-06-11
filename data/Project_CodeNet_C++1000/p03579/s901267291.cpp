#include <iostream>
#include <vector>
#include <queue>

#define ll long long
using namespace std;

ll n;
vector<int> state;
vector<vector<int>> graph;

int bfs() {
    state = vector<int>(n);
    for (int i = 0; i < n; i++)state[i] = -1;
    queue<int> que;
    for (auto x:graph[0])que.push(x);
    que.push(-1);
    int depth = 1;
    while (true) {
        int next = que.front();
        que.pop();
        if (next == -1) {
            if (que.empty())break;
            depth++;
            que.push(-1);
        } else {
            if (state[next] >= 0 && state[next] != depth % 2) return -1;
            state[next] = depth % 2;
            for (auto x:graph[next])
                if (state[x] < 0)que.push(x);
        }
    }
    return 0;
}

int main() {
    ll m;
    cin >> n >> m;
    graph = vector<vector<int>>(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    if (0 > bfs())
        cout << n * (n - 1) / 2 - m;
    else {
        ll count = 0;
        for (auto x:state)if (x)count++;
        cout << count * (n - count) - m << endl;
    }
    return 0;
}