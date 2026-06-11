#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <limits>
#include <random>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstdint>
using namespace std;

#define REP(i,n) for (int i = 0; i < n; i++)
typedef long long ll;

template <class T> struct FenwickTree {

    vector < T > node;
    FenwickTree (int n) : node(n, 0) {}

    void add(int idx, T val) {
        for (int i = idx; i < node.size(); i |= i + 1) {
            node[i] += val;
        }
    }

    void update(int idx, T val) {
        add(idx, -sum(idx, idx + 1));
        add(idx, val);
    }

    T sum(int idx) {
        T ret = 0;
        for (int i = idx - 1; i >= 0; i = (i & (i + 1)) - 1) {
            ret += node[i];
        }
        return ret;
    }

    T sum(int l, int r) {
        return sum(r) - sum(l);
    }

};


long long InversionNumber(vector < int > &arr) {
    ll ret = 0;
    FenwickTree < ll > inst(100010);
    REP(i,arr.size()) {
        ret += inst.sum(arr[i] + 1);
        inst.add(arr[i], 1);
    }
    return ret;
}

ll N;
ll a[100010];

bool check (ll x) {
    vector < int > S(N + 1);
    REP(i,N) {
        if (a[i] >= x) S[i + 1] = 1;
        else S[i + 1] = -1;
    }
    REP(i,N) S[i + 1] = S[i] + S[i + 1];
    int min_v = 1e9;
    REP(i,N + 1) min_v = min(min_v, S[i]);
    REP(i,N + 1) S[i] -= min_v;
    REP(i,N + 1) S[i]++;

    ll inv = InversionNumber(S);
    ll Sum = N * (N + 1) / 2 + 1;
    if (Sum / 2 <= inv) return true;
    return false;
}

int main () {

    cin >> N;
    REP(i,N) cin >> a[i];

    ll l = 0, r = 1e9 + 7;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    }

    cout << l << endl;

    return 0;
}