#include <bits/stdc++.h>

#define debug(x) cout << #x << " = " << x << endl
#define fori(i, ini, lim) for(int i = int(ini); i < int(lim); i++)
#define ford(i, ini, lim) for(int i = int(ini); i >= int(lim); i--)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

const int MAX = 2e5 + 5;
char buf[MAX];
int type[MAX];
set<int> adj[MAX][2];
int n, m;

int main() {
    scanf("%d %d", &n, &m);
    scanf("%s", buf);
    fori(i, 0, n) {
        type[i + 1] = buf[i] == 'A';
    }
    fori(i, 0, m) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][type[v]].insert(v);
        adj[v][type[u]].insert(u);
    }
    set<ii> pq;
    fori(i, 1, n + 1) {
        pq.emplace(min((int) adj[i][0].size(), (int) adj[i][1].size()), i);
    }
    while(!pq.empty() && pq.begin()->first == 0) {
        ii top = *pq.begin(); pq.erase(pq.begin());
        int id = top.second;
        set<int> v = adj[id][0].empty() ? adj[id][1] : adj[id][0];
        for(auto &each : v) {
            if(adj[each][type[id]].count(id)) {
                int score = min((int) adj[each][0].size(), (int) adj[each][1].size());
                pq.erase(ii(score, each));
                adj[each][type[id]].erase(id);
                int new_score = min((int) adj[each][0].size(), (int) adj[each][1].size());
                pq.emplace(new_score, each);
            }
        }
    }
    puts(pq.empty() ? "No" : "Yes");
    return 0;
}
