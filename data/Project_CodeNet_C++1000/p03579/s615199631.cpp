#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> edge(N+1, vector<int>());
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    vector<int> color(N+1, 0);
    color[1] = 1;
    int black=1, white=0;
    queue<int> q;
    q.push(1);
    bool check = true;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int nxt : edge[now]) {
            if (color[nxt] != 0 && color[now] == color[nxt]) {
                check = false;
                break;
            }
            if (color[now]+color[nxt] == 3) continue;
            color[nxt] = 3-color[now];
            if (color[nxt] == 1) black++;
            else white++;
            q.push(nxt);
        }
        if (!check) break;
    }
    if (check) cout << (ll)black*white - M << endl;
    else cout << (ll)N*(N-1)/2 - M << endl;
    return 0;
}