#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <string.h>
using namespace std;

#define NMAX 100001

pair <long long, int> distances[NMAX];
long long v[NMAX], dist[NMAX];
int bij[NMAX], par[NMAX], cnt[NMAX];
vector <int> sons[NMAX];
map <long long, int> idx;

void dfs1(int nod) {
    cnt[nod] = 1;
    dist[nod] = 0LL;
    for (const int x : sons[nod]) {
        dfs1(x);
        dist[nod] = 0LL + dist[nod] + dist[x] + (long long)cnt[x];
        cnt[nod] += cnt[x];
    }
}

void dfs2(int nod, long long sump, int cntp) {
    dist[nod] = 0LL + dist[nod] + sump + (long long)cntp;
    cntp += cnt[nod];
    for (const int x : sons[nod]) {
        dfs2(x,  dist[nod] - (dist[x] + (long long)cnt[x]), cntp - cnt[x]);
    }
}

bool solve(const int n) {
    for (int i = 1; i <= n; i++) {
        idx[v[i]] = i;
    }
    for (int i = n; i >= 2; i--) {
        idx.erase(idx.find(v[i]));
        cnt[i]++;
        for (const int son : sons[i]) {
            cnt[i] += cnt[son];
        }
        long long dp = v[i] + 2LL * cnt[i] - (long long)n;
        if (idx.find(dp) == idx.end()) {
            return false;
        }
        int p = idx[dp];
        sons[p].push_back(i);
        par[i] = p;
    }

    memset(cnt, 0, sizeof(cnt));
    dfs1(1);
    dfs2(1, 0LL, 0);

    for (int i = 1; i <= n; i++)
        if (dist[i] != v[i])
            return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);

    int n;
    // ifstream cin("code.in");
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> distances[i].first;
        distances[i].second = i;
    }
    sort(distances + 1, distances + n + 1);

    for (int i = 1; i <= n; i++) {
        v[i] = distances[i].first;
        bij[i] = distances[i].second;
    }

    if (!solve(n)) {
        cout << "-1\n";
        return 0;
    }

    for (int i = 2; i <= n; i++) {
        cout << bij[par[i]] << " " << bij[i] << '\n';
    }

    return 0;
}
