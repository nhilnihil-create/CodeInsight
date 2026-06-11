/*
.....   .   .   .   .
  .    . .   . .   . .
  .   .....   .   .....
  .  .     .  .  .     .
*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
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
   
using namespace std;
   
template<typename T> void uin(T &a, T b) {
    if (b < a) {
        a = b;
    }
}
   
template<typename T> void uax(T &a, T b) {
    if (b > a) {
        a = b;
    }
}



#define left left228
#define right right228
#define set set228

const int maxn = 200 * 1000 + 228;

int n;
int a[maxn];

struct block
{
    int len, d;
    block() {}
    block(int _len, int _d) {
        len = _len;
        d = _d;
    }
};

int D;
vector<block> v;

void add(block b) {
    if (v.empty()) {
        v.push_back(b);
    } else {
        if (v.back().d == b.d) {
            v.back().len += b.len;
        } else {
            v.push_back(b);
        }
    }
}

void del(int k) {
    while (v.back().len <= k) {
        k -= v.back().len;
        v.pop_back();
    }
    if (k) {
        v.back().len -= k;
    }
}

void inclast() {
    if (v.back().len == 1) {
        int curd = v.back().d;
        v.pop_back();
        add({1, curd + 1});
    } else {
        --v.back().len;
        int d = v.back().d;
        add({1, d + 1});
    }
}

void inc() {
    if (v.back().d != D - 1) {
        inclast();
    } else {
        int len = v.back().len;
        v.pop_back();
        inclast();
        add({len, 0});
    }
}

bool check(int x) {
    D = x;
    v.clear();
    v.push_back({a[1], 0});
    for (int i = 2; i <= n; ++i) {
        if (a[i] > a[i - 1]) {
            add(block(a[i] - a[i - 1], 0));
        } else {
            del(a[i - 1] - a[i]);
            if ((int)v.size() == 1 && v[0].d == x - 1) {
                return 0;
            }
            inc();
        }
    }
    return 1;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int l = 0, r = n;
    while (r - l > 1) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r << '\n';
    return 0;
}
  
  
  
  
