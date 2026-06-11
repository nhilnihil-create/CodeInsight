/*
ЗАПУСКАЕМ 
░ГУСЯ░▄▀▀▀▄░РАБОТЯГУ░░
▄███▀░◐░░░▌░░░░░░░
░░░░▌░░░░░▐░░░░░░░
░░░░▐░░░░░▐░░░░░░░
░░░░▌░░░░░▐▄▄░░░░░
░░░░▌░░░░▄▀▒▒▀▀▀▀▄
░░░▐░░░░▐▒▒▒▒▒▒▒▒▀▀▄
░░░▐░░░░▐▄▒▒▒▒▒▒▒▒▒▒▀▄
░░░░▀▄░░░░▀▄▒▒▒▒▒▒▒▒▒▒▀▄
░░░░░░▀▄▄▄▄▄█▄▄▄▄▄▄▄▄▄▄▄▀▄
░░░░░░░░░░░▌▌░▌▌░░░░░
░░░░░░░░░░░▌▌░▌▌░░░░░
░░░░░░░░░▄▄▌▌▄▌▌░░░░░ 
 */
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")  
#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
     
      
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, const T2 &y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, const T2 &y) { if (x < y) x = y; } 
template<typename T, typename U> inline ostream &operator<< (ostream &_out, const pair<T, U> &_p) { _out << _p.first << ' ' << _p.second; return _out; }
template<typename T, typename U> inline istream &operator>> (istream &_in, pair<T, U> &_p) { _in >> _p.first >> _p.second; return _in; }
template<typename T> inline ostream &operator<< (ostream &_out, const vector<T> &_v) { if (_v.empty()) { return _out; } _out << _v.front(); for (auto _it = ++_v.begin(); _it != _v.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline istream &operator>> (istream &_in, vector<T> &_v) { for (auto &_i : _v) { _in >> _i; } return _in; }
template<typename T> inline ostream &operator<< (ostream &_out, const set<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline ostream &operator<< (ostream &_out, const multiset<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline ostream &operator<< (ostream &_out, const unordered_set<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline ostream &operator<< (ostream &_out, const unordered_multiset<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T, typename U> inline ostream &operator<< (ostream &_out, const map<T, U> &_m) { if (_m.empty()) { return _out; } _out << '(' << _m.begin()->first << ": " << _m.begin()->second << ')'; for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) { _out << ", (" << _it->first << ": " << _it->second << ')'; } return _out; }
template<typename T, typename U> inline ostream &operator<< (ostream &_out, const unordered_map<T, U> &_m) { if (_m.empty()) { return _out; } _out << '(' << _m.begin()->first << ": " << _m.begin()->second << ')'; for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) { _out << ", (" << _it->first << ": " << _it->second << ')'; } return _out; }
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
#define rank rank228
#define y1 y1228                                                         
#define read(FILENAME) freopen(((string)FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen(((string)FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
const int MAXN = 100228;


//10:15
//11:55

int n;
int a[MAXN];
int ss = 1;
int d[MAXN * 8];


void change(int i, int x) {
    while (i) {
        d[i] += x;
        i >>= 1;
    }
}


int rmq(int l, int r) {
    l += ss - 1;
    r += ss - 1;
    int ans = 0;
    while (l <= r) {
        if (l & 1) {
            ans += d[l];
            l++;
        }
        if (!(r & 1)) {
            ans += d[r];
            r--;
        }
        l >>= 1;
        r >>= 1;
    }
    return ans;
}


long long count(int x) {
    for (int i = 0; i < 2 * ss; i++) {
        d[i] = 0;
    }
    long long cur = 0;
    long long res = 0;
    for (int i = 0; i < n; i++) {
        int st = 0;
        if (a[i] > x) {
            st = 1;
        } else {
            st = -1;
        }
        cur += st;
        if (cur < 0) {
            res++;
        }
        res += rmq(n + cur + 2, 2 * n + 1);
        change(ss + n + cur, 1);
    }
    return res;
}


int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
 //   read("input");
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    while (ss <= 2 * n + 1) {
        ss <<= 1;
    }
    long long cnt = 1LL * n * (n + 1) / 2LL;
   // cout << count(20) << endl;
    int l = 1;
    int r = 1000000000;
    while (l != r) {
        int mid = (l + r) >> 1;
        if (count(mid) >= cnt / 2 + 1) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l << '\n';
}

