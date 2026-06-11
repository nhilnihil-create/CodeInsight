#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
using ll = long long;
using pll = pair<ll, ll>;
#define FOR(i, begin, end) for (int i = (begin), i##_end_ = (end); i < i##_end_; i++)
#define IFOR(i, begin, end) for (int i = (end)-1, i##_begin_ = (begin); i >= i##_begin_; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)
#define VREP(s, ite) for (auto ite = s.begin(); ite != s.end(); ++ite)
#define FI first
#define SE second
//#define endl "\n"
#define ciosup  \
    cin.tie(0); \
    ios::sync_with_stdio(false);
#define eb emplace_back
#define vint vector<int>
constexpr ll INF = 1e9 + 7;
constexpr ll MOD = 1e9 + 7;
template <typename T>
void vecin(vector<T> &v, int n = 0)
{
    if (n == 0)
        n = v.size();
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }
}
template <typename T>
void vecout(vector<T> &v, int n = 0)
{
    if (n == 0)
        n = v.size();
    for (int i = 0; i < n - 1; ++i)
    {
        cout << v[i] << " ";
    }
    cout << v[n - 1] << endl;
}


int main()
{
    ciosup;
    vector<vector<int>> G(100005);
    vector<vector<pint>> G2(100005);
    vector<int> inrank(100005);
    unordered_map<int,int> topsort;
    queue<int> zeronode;
    int n, m;
    cin >> n >> m;
    REP(i,n-1+m){
        int a, b;
        cin >> a >> b;
        G[a].emplace_back(b);
        G2[a].emplace_back(make_pair(b, 0));
        G2[b].emplace_back(make_pair(a, 1));
        ++inrank[b];
    }
    FOR(i ,1, n+1){
        if (inrank[i] == 0){
            zeronode.emplace(i);
        }
    }
    int rank = 0;
    while (zeronode.size())
    {
        int curnode = zeronode.front();
        zeronode.pop();
        topsort[curnode] = rank++;
        for (int elem : G[curnode])
        {
            if (--inrank[elem] == 0){
                zeronode.emplace(elem);
            }
        }
    }
    vint ans(n+1, 0);
    FOR(i, 1, n+1)
    {
        int in = 0, rnk = -1;
        for (pint elem:G2[i]){
            if (elem.SE == 1 && rnk < topsort[elem.FI])
            {
                rnk = topsort[elem.FI];
                ans[i] = elem.FI;
            }
        }
    }
    FOR(i,1,n+1){
        cout << ans[i] << endl;
    }
}