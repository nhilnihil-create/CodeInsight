#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define ll long long
#define PI 3.141592653589
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define EPS 1e-7
#define f first
#define s second
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;
const ll MOD = 1e9+7;
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int random_int(int l,int r){return uniform_int_distribution<int>(l,r)(rng);}
ll fast_power(ll x, ll p){
    ll res = 1;
    while(p > 0){
        if(p & 1){
            res = (res * x);
        }
        p = p >> 1;
        x = (x*x);
    }
    return res;
}
bool sorttowers (pair<int,pair<int,int>> p1, pair<int,pair<int,int>> p2)
{
    return (p2.first + p2.second.first) < (p1.first + p1.second.first);
}

int n;
vector<pair<int,pair<int,int>>> tower;
ll dp[3005][20005];

ll solve(int i, int stiff) {
    if (i == n)
        return 0;
    if (dp[i][stiff] != -1) return dp[i][stiff];
    if (tower[i].first <= stiff)
        return dp[i][stiff] = max(solve(i + 1, stiff), solve(i + 1, min(tower[i].second.first, stiff - tower[i].first)) + tower[i].second.second);
    return dp[i][stiff] = solve(i + 1, stiff);
}

int main() {
    IO;
    cin >> n;
    tower.resize(n);
    for (int i = 0; i < n; i++)
        cin >> tower[i].first >> tower[i].second.first >> tower[i].second.second;
    sort(tower.begin(), tower.end(), sorttowers);
    for (int i = 0; i < 3005; i++)
        for (int j = 0; j < 20005; j++)
            dp[i][j] = -1;
    cout << solve(0,20002   );
    return 0;
}
