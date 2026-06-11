#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vll;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define pb push_back
#define rep(i, l, n) for (int i = (l); i < n; i++)
#define rep_cs(i, l, n) for (int i = (l); i <= n; i++)
#define rep_d(j, n) for (int j = n; j >= 0; j--)
#define rep_d_op(j, n, a) for (int j = n; j >= a; j--)

template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}

const int MOD = 1000000007;
const vector<int> dx = {1, 0};
const vector<int> dy = {0, 1};
const ll INF = 1LL << 60;

// int max = *std::max_element(vec.begin(), vec.end());
// int sum = accumulate(list, list + size, 0);

int GCD(int a, int b) { return b ? GCD(b, a % b) : a; }

using Graph = vector<vector<int>>;
Graph G;
vector<bool> seen;
void dfs(const Graph &G, int v)
{
    seen[v] = true;

    for (auto next_v : G[v])
    {
        if (seen[next_v])
            continue;
        dfs(G, next_v);
    }
}

ll dp[110][110000] = {0};
ll w[110];
ll v[110];

int main()
{
    ll n;
    cin >> n;
    vll a(n);
    rep(i, 0, n) cin >> a[i];

    ll all = 1;
    ll bad = 1;

    rep(i, 0, n)
    {
        all *= 3;
        if (a[i] % 2== 0) {
            bad *=2;
        }
    }

    cout << all - bad << endl;
}