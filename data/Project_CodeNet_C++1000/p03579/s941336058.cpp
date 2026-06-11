#include<iostream>
#include<vector>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= end; --i)
#define arep(i, c) for (auto i = (c).begin(); i != (c).end(); ++i)
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

const int MAX_N = 101010;

vector<int> graph[MAX_N];
int color[MAX_N];

bool dfs(int node, int _color) {
    color[node] = _color;
    bool res = true;
    rep(i, 0, graph[node].size()) {
        int next_node = graph[node][i];
        if (color[next_node] < 0) res &= dfs(next_node, _color ^ 1);
        else if (color[next_node] == _color) {
            res = false;
            break;
        }
    }
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    int A, B;
    rep(i, 0, M) {
        cin >> A >> B;
        A--, B--;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }
    rep(i, 0, N) color[i] = -1;
    ll ans = 0;
    if (dfs(0, 0)) {
        ll B = 0, W = 0;
        rep(i, 0, N) {
            if (color[i] == 0) B++;
            else W++;
        }
        ans += B * W - M;
    }
    else {
        ans += N * (N - 1) / 2 - M;
    }
    cout << ans << endl;
    return 0;
}