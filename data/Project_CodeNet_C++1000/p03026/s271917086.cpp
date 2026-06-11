#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(aaa) aaa.begin(), aaa.end()

const int N = 1e4 + 5;
vector<int> g[N];
int c[N], ans[N];
bool used[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    sort(c, c + n);
    reverse(c, c + n);

    queue<int> q;
    q.push(0);
    used[0] = true;

    int k = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ans[node] = c[k++];
        for (int to : g[node]) {
            if (!used[to]) {
                used[to] = true;
                q.push(to);
            }
        }
    }

    ll sum = 0;
    for (int i = 1; i < n; i++) {
        sum += ans[i];
    }

    cout << sum << "\n";
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";

    return 0;
}