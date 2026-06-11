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

int n;

int check(vector<int> &da, int now) {
    deque<Pii> dq;
    stack<Pii> st;
    dq.push_front({0, 0});
    rip(i,n,0) {
        if(dq.back().first < da[i]) {
            dq.push_back({da[i], 1});
        }
        else {
            while(dq.back().first > da[i]) dq.pop_back();
            int look = da[i];
            while(dq.back() == make_pair(look, now)) {
                dq.pop_back(); --look;
            }
            if(dq.back().first == look) {
                auto tmp = dq.back(); dq.pop_back();
                ++tmp.second;
                dq.push_back(tmp);
            }
            else {
                dq.push_back({look, 2});
            }
            if(dq.back().first != da[i]) dq.push_back({da[i], 1});
        }
        if(dq.front().second == 1) return false;
    }
    return true;
}

int main(){
    cin >> n;
    vector<int> da(n);
    rip(i,n,0) cin >> da[i];
    bool ju = true;
    rip(i,n,1) if(da[i] <= da[i-1]) ju = false;
    if(ju) {
        cout << 1 << endl;
        return 0;
    }
    int ng = 1, ok = 300000;
    while(ok-ng > 1) {
        int now = (ok+ng) >> 1;
        if(check(da, now)) ok = now;
        else ng = now;
    }
    cout << ok << endl;
}