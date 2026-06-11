#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<long long> cost(10, -1);
set<int> s;

long long dfs(int n, vector<vector<long long> > &c) {
    s.insert(n);
    long long rec = 1e9;
    if (cost[n] != -1) {
        rec = min(cost[n], rec);
        s.erase(n);
    }
    
    else if (n == 1) {
        rec = min(cost[1] = 0, rec);
        s.erase(n);
    }
    
    else  {
        for (int i = 0; i < 10; i++) {
            if (s.find(i) == s.end())
                rec = min(rec, dfs(i, c) + c[n][i]);
        }
        s.erase(n);
    }
    return rec;
}

int main() {
    int h, w;   cin >> h >> w;
    vector<vector<long long> > c(10, vector<long long>(10)), a(h, vector<long long>(w));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++)
            cin >> c[i][j];
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++)
            cin >> a[i][j];
    }

    for (int i = 0; i < 10; i++) {
        cost[i] = dfs(i, c);
    }

    long long ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (a[i][j] != -1)
                ans += cost[a[i][j]];
        }
    }

    cout << ans << endl;
    return 0;
}