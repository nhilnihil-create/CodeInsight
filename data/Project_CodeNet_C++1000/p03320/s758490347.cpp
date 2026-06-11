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


using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll INF = 1e16;
const ll MOD = 1e9 + 7;

#define REP(i, n) for(ll i = 0; i < n; i++)




ll sum(ll n){
    ll s = 0;
    for(ll i = n; i > 0; i /= 10){
        s += i % 10;
    }
    return s;
}

int main() {
    ll k;
    cin >> k;
    
    cout << 1 << endl;
    ll n = 1, d = 1;
    for (ll i = 1;i < k;i ++) {
        if (sum(n + d) * (n + 10 * d) < sum(n + 10 * d) * (n + d)) d *= 10;
        n += d;
        cout << n << endl;
    }
}