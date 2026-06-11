#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
#define repi(i, n, init) for (ll i = init; i < (n); i++)
vector<bool> seen;
void dfs(vector<ll> G[], int i)
{
    for (int e : G[i])
    {
        if(!seen[e]){
            seen[e] = true;
            dfs(G,e);
        }
    }
}
int main()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> G[n];
    seen.resize(n, false);
    repi(i, m, 0)
    {
        int x, y, z;
        cin >> x >> y >> z;
        x--;
        y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    ll ans = 0;
    repi(i,n,0){
        if(!seen[i]){
            dfs(G,i);
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}