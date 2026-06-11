#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <random>
#include <cstdio>
#include <cstring>
#include <cmath>

// for i in f..<t {... : as Swift
#define forin(i, f, t) for(ll i = f; i < t; i++)

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    vector<P> lsc, rsc;
    ll n;
    cin >> n;
    forin(i, 0, n) {
        ll l, r;
        cin >> l >> r;
        lsc.push_back(P{i, l});
        rsc.push_back(P{i, r});
    }
    sort(lsc.begin(), lsc.end(), [](P lhs, P rhs) {
        return lhs.second < rhs.second;
    });
    sort(rsc.begin(), rsc.end(), [](P lhs, P rhs) {
        return lhs.second > rhs.second;
    });
    
    vector<bool> used(n, false);
    
    ll lenU = 0;
    ll count = 0;
    ll pos = 0;
    auto ls = lsc, rs = rsc;
    bool vec = true;
    while (count++ < n) {
        auto& cvec = vec ? ls : rs;
        auto &cp = cvec.back();
        while (used[cp.first]) {
            cvec.pop_back();
            cp = cvec.back();
        }
        if ((vec && pos < cp.second) || (!vec && cp.second < pos)) {
            lenU += abs(cp.second - pos);
            pos = cp.second;
        }
        used[cp.first] = true;
        vec = !vec;
    }
    lenU += abs(pos);
    
    ll lenV = 0;
    ls = lsc; rs = rsc;
    count = 0;
    pos = 0;
    vec = false;
    used.assign(n, false);
    while (count++ < n) {
        auto& cvec = vec ? ls : rs;
        auto &cp = cvec.back();
        while (used[cp.first]) {
            cvec.pop_back();
            cp = cvec.back();
        }
        if ((vec && pos < cp.second) || (!vec && cp.second < pos)) {
            lenV += abs(cp.second - pos);
            pos = cp.second;
        }
        used[cp.first] = true;
        vec = !vec;
    }
    lenV += abs(pos);
    
    
    cout << max(lenU, lenV) << endl;
    
}

