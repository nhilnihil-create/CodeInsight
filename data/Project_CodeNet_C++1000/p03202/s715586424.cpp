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
#include <float.h>
#include <math.h>
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

ll ll_gcd(ll a, ll b) {
    if (a < b) return ll_gcd(b, a);
    ll r;
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
    ll n;
    cin >> n;
    vector<ll> z(n);
    ll flag = 0;
    ll bb = 200100;
    for (int i = 0; i < n; i++) {
        cin >> z[i];
        if (i > 0 && z[i] <= z[i - 1])flag = 1;
        z[i] = min(bb, z[i]);
    }
    if (flag == 0)cout << 1 << endl;
    else {
        ll ok = 200000;
        ll ng = 1;
        while (ok - ng > 1) {
            ll mid = (ok + ng) / 2;
            vector<ll> x(210000);
            priority_queue<ll> q;
            ll fl = 0;
            for (int i = 1; i < n; i++) {
                if (z[i - 1] >= z[i]) {
                    while (!q.empty()) {
                        if (z[i] < q.top()) {
                            x[q.top()] = 0;
                            q.pop();
                        }
                        else break;
                    }
                    ll now = z[i];
                    while (true) {
                        x[now]++;
                        q.push(now);
                        if (x[now] == mid) {
                            x[now] = 0;
                            now--;
                        }
                        else break;
                    }
                    if (x[0] > 0) {
                        fl = 1;
                        break;
                    }
                }
            }
            if (fl == 0)ok = mid;
            else ng = mid;
        }
        cout << ok << endl;
    }
}