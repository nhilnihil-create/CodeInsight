#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define MAXN 100001
bool used[MAXN];
bool start[MAXN];
vector<ll> vec[MAXN]; //to
int memo[MAXN];
int depth(int x) {
    if (used[x]) return memo[x];
    int max = 0;
    for (int i = 0; i < vec[x].size(); i++) {
        if (max < depth(vec[x][i])) {
            max = depth(vec[x][i]);
        }
    }
    memo[x] = max + 1;
    used[x] = true;
    return max + 1;
}
int main() {
    int n, m;
    cin >> n >> m;
    memset(start, true, sizeof(start));
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        vec[x].push_back(y);
        start[y] = false;
    }
    memset(used, false, sizeof(used));
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        if (start[i]) {
            if (depth(i) > ret) {
                ret = depth(i);
            }
        }
    }
    cout << ret - 1 << endl;
    return 0;
}