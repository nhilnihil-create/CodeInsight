#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> neighbor[100'000];
bool isVisited[100'000];
int color[100'000];

bool dfs(int node, int col)
{
    isVisited[node] = true;
    color[node] = col;

    bool result = true;

    for (const int c : neighbor[node]) {
        if (isVisited[c]) {
            result = result && color[node] != color[c];
        } else {
            result = result && dfs(c, 1 - col);
        }
    }

    return result;
}

int main()
{
    int64_t n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        neighbor[a].push_back(b);
        neighbor[b].push_back(a);
    }

    fill(isVisited, isVisited + n, false);
    if (dfs(0, 0)) {
        int64_t cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += color[i] == 0 ? 1 : 0;
        }
        int64_t result = cnt * (n - cnt) - m;
        cout << result << endl;
    } else {
        cout << n * (n - 1) / 2 - m << endl;
    }

    return 0;
}