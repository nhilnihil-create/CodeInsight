#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>

#define DIV 1000000007
using namespace std;
using ll = long long;
using ldb = long double;

typedef struct {
    vector<int> edge;
    int deg = 0;
    bool vi = 0;
    int tpr = 0;
    int par = 0;
}node_t;
vector<node_t> node;

int main() {
    int N, M;
    cin >> N >> M;

    node = vector<node_t>(N + 1);
    for (int i = 0; i < N - 1 + M; i++) {
        int a, b;
        cin >> a >> b;
        node[a].edge.push_back(b);
        node[b].deg++;
    }
    
   
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (node[i].deg == 0) {
            q.push(i);
            node[i].vi = true;
            node[i].tpr = 1;
            break;
        }
    }

    int cnt = 2;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto to : node[x].edge) {
            //if (node[to].vi) continue;
            //node[to].vi = true;
            node[to].tpr = cnt;
            cnt++;
            node[to].deg--;
            if (node[to].deg == 0) {
                q.push(to);
                node[to].par = x;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << node[i].par << endl;
    }

}
