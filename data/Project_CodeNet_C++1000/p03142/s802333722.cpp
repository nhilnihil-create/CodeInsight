#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111, inf = 1000111222;

vector<int> v[max_n];

vector<int> tout;
vector<int> pr[max_n];
int n, m;
int dp[max_n];
int dst[max_n];

bool vis[max_n];

void dfs(int cur) {
    vis[cur] = 1;
    for (int to : v[cur]) {
        if (!vis[to]) {
            dfs(to);
        }
    }
    tout.PB(cur);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < n + m - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        v[a].PB(b);
        pr[b].PB(a);
    }
    int start = -1;
    for (int i = 0; i < n; ++i) {
        if (pr[i].size() == 0) {
            if (start == -1) {
                start = i;
            } else {
                exit(228);
            }
        }
    }
    for (int i = 0; i < max_n; ++i) {
        dst[i] = -5;
    }
    dfs(start);
    dst[start] = 0;
    dp[start] = -1;

    while (!tout.empty()) {
        int cur = tout.back();
        dst[cur] = 0;
        tout.pop_back();
        for (int p : pr[cur]) {
            if (dst[p] == -5) {
                exit(229);
            }
            if (dst[p] + 1 > dst[cur]) {
                dst[cur] = dst[p] + 1;
                dp[cur] = p;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << dp[i] + 1 << "\n";
    }
    return 0;
}



