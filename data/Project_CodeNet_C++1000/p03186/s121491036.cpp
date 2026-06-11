// O O O O O O O O O O O O O O O OO O OO O OO O O O TTCH O TTTCH O TTTCH O O O O
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx")
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stdio.h>
#include <cstdio>
#include <math.h>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <deque>
#include <random>
#include <iomanip>
#include <bitset>
#include <cassert>
 
using namespace std;

#define int long long
#define y1 y11
#define double long double
#define less less228
#define left left228
#define right right228
#define list list228



template<typename T> void uin(T &a, T b) {
    if (b < a) a = b;
}
template<typename T> void uax(T &a, T b) {
    if (b > a) a = b;
}
 
 
random_device rnd;
 
template<typename T> void shuffle(vector< T > &v) {
    for (int i = 1; i < (int)v.size(); ++i) {
        swap(v[rnd() % i], v[i]);
    }
    for (int i = (int)v.size() - 1; i; --i) {
        swap(v[rnd() % i], v[i]);
    }
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    swap(a, b);
    if (a + b >= c - 1) {
        cout << a + c << endl;
    } else {
        cout << a + a + b + 1 << endl;
    }
    return 0;
}
// RU_023

