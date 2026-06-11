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
int id = 0;

void dfs(vector<vector<int>> &da, vector<int> &c, vector<int> &used, int now){
    if(used[now] >= 0) return;
    used[now] = c[id];
    ++id;
    rip(i, da[now].size(), 0){
        dfs(da, c, used, da[now][i]);
    }
    return;
}

int main(){
    int n; cin >> n;
    vector<vector<int>> da(n, vector<int>(0));
    rip(i,n-1,0){
        int a,b; cin >> a >> b;
        a--;b--;
        da[a].push_back(b);
        da[b].push_back(a);
    }
    vector<int> c(n);
    rip(i,n,0) cin >> c[i];
    sort(all(c));
    reverse(all(c));
    vector<int> ans(n, -1);
    dfs(da, c, ans, 0);
    ll m = 0;
    rip(i,n,1) m += (ll)ans[i];
    cout << m << endl;
    vdeb(ans);
}