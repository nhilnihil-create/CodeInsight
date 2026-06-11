#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int N, M;
    cin >> N >> M;
    string s;
    cin >> s;
    vector<vector<int>> edge(N+1);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    vector<int> na(N+1, 0), nb(N+1, 0);
    for (int i = 1; i <= N; i++) {
        if (s[i-1] == 'A') {
            for (int n : edge[i]) na[n]++;
        }else {
            for (int n : edge[i]) nb[n]++;
        }
    }
    queue<int> q;
    int cnt = N;
    vector<bool> use(N+1, true);
    for (int i = 1; i <= N; i++) {
        if (na[i] == 0 || nb[i] == 0) {
            q.push(i);
            use[i] = false;
        }
    }
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        cnt--;
        if (s[now-1] == 'A') {
            for (int nxt : edge[now]) {
                na[nxt]--;
                if (use[nxt] && na[nxt] == 0) {
                    q.push(nxt);
                    use[nxt] = false;
                }
            }
        }else {
            for (int nxt : edge[now]) {
                nb[nxt]--;
                if (use[nxt] && nb[nxt] == 0) {
                    q.push(nxt);
                    use[nxt] = false;
                }
            }
        }
    }
    if (cnt > 0) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}