#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <cassert>
#include <fstream>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

const ll mod = 1e9 + 7;

vector<string> g;

vector<int> elem;
vector<int> rrank;

void init(int num)
{
    elem = vector<int>(num, 0);
    rrank = vector<int>(num, 0);
    
    for (int i = 0; i < num; ++i)
    {
        elem[i] = i;
    }
}

int dfs(int num)
{
    if (elem[num] == num)
    {
        return num;
    }
    else
    {
        elem[num] = dfs(elem[num]);
        return elem[num];
    }
}

void unite(int a, int b)
{
    a = dfs(a);
    b = dfs(b);
    
    if (a == b)
    {
        return;
    }
    else
    {
        elem[b] = a;
    }
}

int main() {
    
    
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    ll n, m;
    cin >> n >> m;
    init(n);
    
    vector<P> v(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> v[i].first >> v[i].second;
        v[i].first--;
        v[i].second--;
    }
    
    vector<ll> mm(n, 1);
    
    reverse(v.begin(), v.end());
    
    vector<ll> ret(m);
    ll cur = (n * (n - 1)) / 2;
    for (int i = 0; i < m; ++i)
    {
        ret[m - 1 - i] = max(0ll, cur);
        if (dfs(v[i].first) == dfs(v[i].second))
        {
            continue;
        }
        cur -= mm[dfs(v[i].first)] * mm[dfs(v[i].second)];
        mm[dfs(v[i].first)] += mm[dfs(v[i].second)];
        unite(v[i].first, v[i].second);
    }
    
    for (int i = 0; i < m; ++i)
    {
        cout << ret[i] << endl;
    }

    return 0;
}