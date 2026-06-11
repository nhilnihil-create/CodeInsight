#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int N;
    cin >> N;
    vector<vector<int>> edge(N+1, vector<int>());
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    vector<int> c(N);
    for (int i = 0; i < N; i++) cin >> c[i];
    sort(c.begin(), c.end());
    reverse(c.begin(), c.end());
    queue<int> q;
    q.push(1);
    vector<int> ans(N+1, 0);
    ans[1] = c[0];
    int pos = 1;
    ll sum = 0;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int nxt : edge[now]) {
            if (ans[nxt] > 0) continue;
            ans[nxt] = c[pos];
            sum += c[pos];
            pos++;
            q.push(nxt);
        }
    }
    cout << sum << endl;
    for (int i = 1; i <= N; i++) {
        if (i < N) printf("%d ", ans[i]);
        else printf("%d\n", ans[i]);
    }
}
