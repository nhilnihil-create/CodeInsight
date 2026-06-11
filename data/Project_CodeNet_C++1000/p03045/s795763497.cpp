#include <bits/stdc++.h>
#include <math.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<int, int> P;

const int MOD = 1000000007;
const int INF_32 = 1LL << 30;
const int64_t INF_64 = 1LL << 60;

template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T& val)
{
    std::fill((T*)array, (T*)(array + N), val);
}
void dfs(int v, Graph& G, vector<bool>& seen)
{
    seen[v] = true;
    for (auto nv : G[v]) {
        if (seen[nv])
            continue;
        dfs(nv, G, seen);
    }
}
int main()
{
    int N, M;
    cin >> N >> M;
    Graph G(N);
    vector<bool> seen(N, false);
    for (int i = 0; i < M; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        x--, y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    int ans = 0;
    for (int v = 0; v < N; v++) {
        if (seen[v])
            continue;
        dfs(v, G, seen);
        ans++;
    }

    cout << ans << endl;
    return 0;
}