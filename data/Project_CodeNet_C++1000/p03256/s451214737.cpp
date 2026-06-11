#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <typeinfo>
#include <numeric>
#include <functional>
#include <unordered_map>
#include <bitset>
#include <stack>


using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll INF = 1e16;
const ll MOD = 1e9 + 7;

#define REP(i, n) for(ll i = 0; i < n; i++)




int main() {
    ll n, m;
    string s;
    cin >> n >> m >> s;
    vector<vector<ll>> g(n), c(n, vector<ll>(2));
    REP(i, m){
        ll a, b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
        c[a][s[b] - 'A']++;
        c[b][s[a] - 'A']++;
    }
    
    queue<ll> que;
    vector<bool> used(n);
    REP(i, n){
        if(c[i][0] == 0 || c[i][1] == 0){
            que.push(i);
            used[i] = true;
        }
    }
    
    ll cnt = que.size();
    while(!que.empty()){
        ll u = que.front(); que.pop();
        REP(i, g[u].size()){
            ll v = g[u][i];
            c[v][s[u] - 'A']--;
            if(c[v][s[u] - 'A'] == 0 && !used[v]){
                que.push(v);
                cnt++;
                used[v] = true;
            }
        }
    }
    cout << ((cnt != n)? "Yes" : "No") << endl;
}
