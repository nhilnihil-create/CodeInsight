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

int main() {
    int h,w,n; cin >> h >> w >> n;
    vector<vector<int>> da(w, vector<int>(0));
    rip(i,n,0) {
        int x,y; cin >> x >> y;
        --x;--y;
        da[y].push_back(x);
    }
    rip(i,w,0) sort(all(da[i])), da[i].emplace_back(h);
    int ans = h*2, now = 0;
    rip(i,w,0) {
        rip(j,da[i].size(),0) {
            if(da[i][j] > now) {
                chmin(ans, da[i][j]);
            }
            else if(da[i][j] == now) {
                ++now;
            }
        }
        ++now;
    }
    cout << ans << endl;
}