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
#define mapa make_pair
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
    for (int i = 0;i < da.size();i++) vdeb(da[i]);
    std::cout << std::endl;
}

using namespace std;

int main(){
    ll n, a, b; cin >> n >> a >> b;
    if(a*b < n || a+b-1 > n){
        cout << -1 << endl;
        return 0;
    }
    vector<int> ans(n);
    rip(i,b,0) ans[i] = b-i-1;
    int now = b, lam = n-a-b+1;
    while(now < n){
        int nxt = 1 + min((int)b-1, lam);
        lam -= nxt-1;
        now += nxt;
        rip(i,nxt, 0){
            ans[now-i-1] = now-nxt+i;
        }
    }
    rip(i,n,0) ++ans[i];
    vdeb(ans);
}
