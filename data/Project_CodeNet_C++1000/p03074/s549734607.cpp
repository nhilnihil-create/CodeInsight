#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <functional>
#include <ctime>
#include <cmath>
#include <limits>
#include <numeric>
#include <type_traits>
#include <iomanip>
using namespace std;
using ll = long long;

unsigned euclidean_gcd(unsigned a, unsigned b) {
    if (a < b) return euclidean_gcd(b, a);
    unsigned r;
    while ((r = a % b)) {
        a = b;
        b = r;
    }
    return b;
}

class UnionFind {
public:
    vector <ll> par;
    vector <ll> siz;
    UnionFind(ll sz_) : par(sz_), siz(sz_, 1LL) {
        for (ll i = 0; i < sz_; ++i) par[i] = i;
    }
    void init(ll sz_) {
        par.resize(sz_);
        siz.assign(sz_, 1LL);
        for (ll i = 0; i < sz_; ++i) par[i] = i;
    }
    ll root(ll x) {
        while (par[x] != x) {
            x = par[x] = par[par[x]];
        }
        return x;
    }
    bool merge(ll x, ll y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (siz[x] < siz[y]) swap(x, y);
        siz[x] += siz[y];
        par[y] = x;
        return true;
    }

    bool issame(ll x, ll y) {
        return root(x) == root(y);
    }

    ll size(ll x) {
        return siz[root(x)];
    }
};

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

long long modinv(long long a, long long mod) {
    return modpow(a, mod - 2, mod);
}


int main() {
    int n, k;
    cin >> n >> k;
    string p;
    cin >> p;
    vector<int> z;
    int r = 0;
    for (int i = 0; i < n; i++) {
        if (p.at(i) == '0' && z.size() % 2 == 0) {
            z.push_back(r);
            r = 1;
        }
        else if (p.at(i) == '1' && z.size() % 2 == 1) {
            z.push_back(r);
            r = 1;
        }
        else { r++; }
    }
    z.push_back(r);
    if (z.size() % 2 == 0)z.push_back(0);
    if (z.size() <= 2 * k + 1)cout << n << endl;
    else {
        int t = 0;
        for (int i = 0; i < 2*k+1; i++) {
            t += z.at(i);
        }
        int ans = t;
        for (int i = 0; i < n*2; i+=2) {
            if (z.size() <= 2 * k + 2 + i)break;
            t -= z.at(i)+z.at(i+1);
            t += z.at(2 * k + 1 + i) + z.at(2 * k + 2 + i);
                ans = max(ans, t);
                
        }
        cout << ans << endl;
    }
}