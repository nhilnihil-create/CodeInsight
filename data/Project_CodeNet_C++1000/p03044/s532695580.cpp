#include <bits/stdc++.h>
using namespace std;

void print() { cout << endl; }
template <typename Head, typename... Tail>
void print(Head head, Tail... tail) {
    int size = sizeof...(Tail);
    cout << head;
    if (size > 0) {
        cout << " ";
    }
    print(tail...);
}

void print0() {}
template <typename Head, typename... Tail>
void print0(Head head, Tail... tail) {
    cout << head;
    print0(tail...);
}

struct edge {
    int u;
    int v;
    int w;
};

int main() {
    int N;
    cin >> N;

    map<int, vector<pair<int, int>>> uv;
    //    map<int, vector<pair<int, int>>> vu;

    int E = N - 1;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u;
        cin >> v;
        cin >> w;
        u--;
        v--;
        w = (w % 2 == 0) ? 2 : 1;
        uv[u].push_back(pair<int, int>(v, w));
        uv[v].push_back(pair<int, int>(u, w));
        //        vu[v].push_back(pair<int, int>(u, w));
    }

    vector<int> colors(N);
    for (int i = 0; i < N; i++) {
        colors[i] = -1;
    }
    colors[0] = 1;

    stack<int> nodeids;
    nodeids.push(0);
    while (!nodeids.empty()) {
        int nod = nodeids.top();
        nodeids.pop();
        for (auto e : uv[nod]) {
            int v = e.first;
            int w = e.second;
            if (colors[v] == -1) {
                if (w == 2) {
                    colors[v] = colors[nod];
                } else {
                    colors[v] = 1 - colors[nod];
                }
                nodeids.push(v);
            }
        }
        // for (auto e : vu[nod]) {
        //     int u = e.first;
        //     int w = e.second;
        //     if (colors[u] == -1) {
        //         if (w == 2) {
        //             colors[u] = colors[nod];
        //         } else {
        //             colors[u] = 1 - colors[nod];
        //         }
        //         nodeids.push(u);
        //     }
        // }
    }
    for (int i = 0; i < N; i++) {
        cout << colors[i] << endl;
    }
}
