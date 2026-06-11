#include<iostream>
#include<vector>
#include<string>
#define MAX_N 2 * 100001
using namespace std;

typedef struct edge_count {
    int A, B;
} EC;

vector<int> graph[MAX_N];
EC node_state[MAX_N];
bool deleted[MAX_N];
string s;

void dfs(int u) {
    if (deleted[u]) return;
    deleted[u] = true;
    for (int i = 0; i < graph[u].size(); i++) {
        if (s[u] == 'A') node_state[graph[u][i]].A--;
        else node_state[graph[u][i]].B--;
        if (node_state[graph[u][i]].A == 0 || node_state[graph[u][i]].B == 0) dfs(graph[u][i]);
    }
    return;
}

int main() {
    int N, M, a, b;
    cin >> N >> M >> s;
    for (int i = 0; i < N; i++) {
        node_state[i].A = node_state[i].B = 0;
    }
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
        if (s[a] == 'A') node_state[b].A++;
        else node_state[b].B++;
        if (s[b] == 'A') node_state[a].A++;
        else node_state[a].B++;
        if (a == b) {
            if (s[a] == 'A') node_state[b].A--;
            else node_state[b].B--;
        }
    }
    for (int i = 0; i < N; i++) deleted[i] = false;
    for (int i = 0; i < N; i++) {
        if (node_state[i].A == 0 || node_state[i].B == 0) dfs(i);
    }
    for (int i = 0; i < N; i++) {
        if (! deleted[i]) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}