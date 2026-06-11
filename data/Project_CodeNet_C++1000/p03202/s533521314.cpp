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




int n;
vector<ll> a;

bool ok(ll x){
    map<ll, ll> mp;
    for(ll i = 1; i < n; i++){
        if(a[i - 1] >= a[i]){
            mp.erase(mp.lower_bound(a[i] + 1), mp.end());
            mp[a[i]]++;
            ll t = a[i];
            while(mp[t] >= x && t > 1){
                mp[t - 1] += mp[t] / x;
                mp[t] %= x;
                t--;
            }
        }
    }
    return (mp[1] < x)? true : false;
}

int main() {
    cin >> n;
    a.resize(n);
    REP(i, n){
        cin >> a[i];
    }
    bool f = true;
    for(ll i = 1; i < n; i++){
        if(a[i - 1] >= a[i]){
            f = false;
            break;
        }
    }
    if(f){
        cout << 1 << endl;
        return 0;
    }
    ll l = 1, r = 1e10;
    while(r - l > 1){
        ll c = (l + r) / 2;
        if(ok(c)){
            r = c;
        }
        else{
            l = c;
        }
    }
    cout << r << endl;
}
