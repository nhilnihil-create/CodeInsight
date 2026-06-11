#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include <set>

#define DIV 1000000007
using namespace std;
using ll = long long;

typedef struct {
    vector<int> edge;
    int clr;
    int visit;
}node_t;
vector<node_t> node;

queue<int> q;
bool judge() {
    int x = q.front();
    q.pop();

    for (auto to : node[x].edge) {
        if (node[to].visit) {
            if (node[x].clr == 1 && node[to].clr == 1)
                return false;
            else if (node[x].clr == -1 && node[to].clr == -1)
                return false;
        }

        else {
            q.push(to);
            node[to].visit = 1;
            if (node[x].clr == 1)
                node[to].clr = -1;
            else if (node[x].clr == -1)
                node[to].clr = 1;
        }
    }
    if (!q.empty())
        return judge();
    return true;
}

int main() {
    ll N, M;
    cin >> N >> M;
    node = vector<node_t>(N + 1);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        node[a].edge.push_back(b);
        node[b].edge.push_back(a);
    }
    q.push(1);
    node[1].clr = 1;
    node[1].visit = 1;

    if (judge()) {
        ll B = 0, W = 0;
        for (int i = 1; i <= N; i++) {
            if (node[i].clr == 1) B++;
            else if (node[i].clr == -1)W++;
        }
        cout << B * W - M << endl;
    }
    else {
        cout << N * (N - 1) / 2 - M << endl;
    }
}
