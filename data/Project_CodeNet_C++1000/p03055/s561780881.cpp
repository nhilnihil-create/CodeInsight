//#define _GLIBCXX_DEBUG
#include "bits/stdc++.h"

using namespace std;

//------------------------------- Libraries --------------------------------//

//------------------------------- Type Names -------------------------------//

using i64 = int_fast64_t;

using seika = string;
//akari : 1D, yukari : 2D, maki : 3D vector
template <class kizuna>
using akari = vector<kizuna>;
template <class yuzuki>
using yukari = akari<akari<yuzuki>>;
template <class tsurumaki>
using maki = akari<yukari<tsurumaki>>;
//akane : ascending order, aoi : decending order
template <class kotonoha>
using akane = priority_queue<kotonoha, akari<kotonoha>, greater<kotonoha>>;
template <class kotonoha>
using aoi = priority_queue<kotonoha>;

//------------------------------- Dubug Functions ---------------------------//
inline void print()
{
    cout << endl;
}
template <typename First, typename... Rest>
void print(const First &first, const Rest &... rest)
{
    cout << first << ' ';
    print(rest...);
}
//------------------------------- Solver ------------------------------------//

void solve()
{
    int n;
    cin >> n;
    yukari<int> g(n);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    akari<int> dp(n), dp2(n);
    int s = -1, maxi = 0;
    auto dfs = [&](auto &&dfs, akari<int> &d, int v, int p) -> void {
        for (int nv : g[v])
        {
            if (nv == p)
            {
                continue;
            }
            d[nv] = d[v] + 1;
            if (maxi < d[nv])
            {
                maxi = d[nv];
                s = nv;
            }
            dfs(dfs, d, nv, v);
        }
    };
    dp[0] = 0;
    dfs(dfs, dp, 0, -1);
    dp2[s] = 0;
    dfs(dfs, dp2, s, -1);
    int x = *max_element(dp2.begin(), dp2.end());
    cout << (x % 3 != 1 ? "First" : "Second") << endl;
}

int main()
{
    solve();
    return 0;
}