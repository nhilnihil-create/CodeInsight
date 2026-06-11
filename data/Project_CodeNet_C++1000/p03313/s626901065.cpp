// #include "pch.h"
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <climits>
#include <string>
#include <cmath>
#include <bitset>
#include <complex>
#include <functional>
#include <ctime>
#include <cassert>
#include <fstream>
#include<unordered_map>
#include <stack>
#include <random>

typedef long long ll;
typedef std::pair<int, int> Pii;
typedef std::pair<long long, long long> Pll;
typedef std::pair<double, double> Pdd;

#define rip(i, n, s) for (int i = (s);i < (int)( n ); i++)
#define all(a) a.begin(), a.end()
#define MM << " " <<

template<typename T>
using MaxHeap = std::priority_queue<T>;
template<typename T>
using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

template<typename T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template<typename T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<typename T>
void vdeb(std::vector<T> &da) {
    for (int i = 0;i < da.size();i++) {
        if (i == da.size() - 1) std::cout << da[i];
        else std::cout << da[i] << ' ';
    }
    std::cout << std::endl;
}
template<typename T>
void vdeb(std::vector<std::vector<T>> &da) {
    for (int i = 0;i < da.size();i++) {
        std::cout << i << ' ';
        vdeb(da[i]);
    }
    std::cout << std::endl;
}

using namespace std;

typedef pair<Pii, Pii> P;

P change(P x, P y) {
    set<Pii> pq;
    pq.insert(x.first);   
    pq.insert(x.second);   
    pq.insert(y.first);   
    pq.insert(y.second);
    auto a = *(--pq.end());
    pq.erase(a);
    auto b = *(--pq.end());
    return {a, b};
}

int main() {
    int n; cin >> n;
    vector<int> da((1 << n));
    rip(i,1 << n,0) cin >> da[i];
    vector<pair<Pii,Pii>> dp((1 << n));
    int m = 1 << n;
    rip(i,m,0) {
        dp[i] = {{da[i], i},{da[0], 0}};
        int now = 1;
        rip(j,n,0) {
            if(now&i) {
                dp[i] = change(dp[i], dp[i-now]);
            }
            now <<= 1;
        }
    }
    vector<int> ans(m);
    rip(i,m,1) {
        ans[i] = max(ans[i-1], dp[i].first.first + dp[i].second.first);
    }
    rip(i,m,1) {
        printf("%d\n", ans[i]);
    }
}