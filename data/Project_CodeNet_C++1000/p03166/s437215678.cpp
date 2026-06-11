#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define reps(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; --i)
#define rreps(i, n) for (int i = ((int)(n)); i > 0; --i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define repc2(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define inf 2e9
#define linf 9000000000000000000ll
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

#define N 100000
int n, m;
int max_path_length[N];
int indegree[N];
bool seen[N];
struct edge {
    int to;
    edge(int to) : to(to) {}
};
vector<edge> G[N];

int rec(int s) {
    if (seen[s])
        return max_path_length[s];
    seen[s] = true;
    int res = 0;
    for (const auto &e : G[s]) {
        res = max(res, rec(e.to) + 1);
    }
    return max_path_length[s] = res;
}
int main() {
    cin >> n >> m;
    rep(i, m) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        indegree[y]++;
        G[x].push_back(edge(y));
    }
    rep(i, n) {
        if (indegree[i] == 0) {
            rec(i);
        }
    }
    cout << *max_element(begin(max_path_length), end(max_path_length)) << endl;
    return 0;
}