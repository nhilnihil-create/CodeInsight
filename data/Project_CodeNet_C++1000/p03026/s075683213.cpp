#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
vector<int> G[10010];
vector<int> c;
int main () {
    cin >> N;    
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> v(N, -1);
    queue<int> que;
    v[0] = 0;
    que.push(0);
    int k = 1;
    while (que.size()) {
        int x = que.front();
        que.pop();
        for (auto y: G[x]) {
            if (v[y] == -1) {
                v[y] = k++;
                que.push(y);
            }
        }
    }
    vector<int> c(N);
    int sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> c[i];
        sum += c[i];
    }
    sort(c.begin(), c.end());
    reverse(c.begin(), c.end());
    cout << sum-c[0] << endl;
    for (int i = 0; i < N; i++) {
        cout << c[v[i]];
        if (i != N-1) {
            cout << " ";
        }
    }
    cout << endl;
}