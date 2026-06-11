#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int N;
    cin >> N;
    if (N == 1 || N == 3) {
        cout << "First" << endl;
        return 0;
    }
    if (N == 2) {
        cout << "Second" << endl;
        return 0;
    }
    vector<vector<int>> edge(N+1, vector<int>());
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    vector<int> dist(N+1, 1000000);
    dist[1] = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int nxt : edge[now]) {
            if (dist[nxt] > dist[now]+1) {
                dist[nxt] = dist[now]+1;
                q.push(nxt);
            }
        }
    }
    int distmax = 0;
    int pos = 0;
    for (int i = 1; i <= N; i++) {
        if (dist[i] > distmax) {
            distmax = dist[i];
            pos = i;
        }
    }
    
    for (int i = 1; i <= N; i++) dist[i] = 1000000;
    dist[pos] = 0;
    q.push(pos);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int nxt : edge[now]) {
            if (dist[nxt] > dist[now]+1) {
                dist[nxt] = dist[now]+1;
                q.push(nxt);
            }
        }
    }
    int rad = 0;
    pos = 0;
    for (int i = 1; i <= N; i++) {
        if (dist[i] > rad) {
            rad = dist[i];
            pos = i;
        }
    }
    if (rad % 3 == 1) cout << "Second" << endl;
    else cout << "First" << endl;
    return 0;
}