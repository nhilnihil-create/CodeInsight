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
#define Yes(condition) if(condition){ cout << "Yes" << '\n'; }else{ cout << "No" << '\n'; }
#define YES(condition) if(condition){ cout << "YES" << '\n'; }else{ cout << "NO" << '\n'; }
#define yes(condition) if(condition){ cout << "yes" << '\n'; }else{ cout << "no" << '\n'; }





int main() {
    ll h, w, n;
    cin >> h >> w >> n;
    vector<pair<ll, ll>> v(n);
    REP(i, n){
        ll x, y;
        cin >> y >> x;
        v[i] = {x, y};
    }
    
    sort(v.begin(), v.end());
    
    ll ans = h;
    ll l = 1, u = 1;
    REP(i, n){
        if(v[i].first > l){
            u += v[i].first - l;
            l = v[i].first;
        }
        if(v[i].second > u){
            ans = min(ans, v[i].second - 1);
        }
        else if(v[i].second == u){
            u++;
        }
        // cerr << i << ": " << ans << ' ' << l << ' ' << u << ' ' << v[i].first << ' ' << v[i].second << endl;
    }
    cout << ans << endl;
}
