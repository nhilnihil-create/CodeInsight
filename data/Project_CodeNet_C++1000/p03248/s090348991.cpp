//
//  ROIGold.cpp
//  Main calisma
//
//  Created by Rakhman on 05/02/2019.
//  Copyright © 2019 Rakhman. All rights reserved.
//

#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <iterator>

#define ios ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
#define S second
#define F first
#define pb push_back
#define nl '\n'
#define NL cout << '\n';
#define EX exit(0)
#define all(s) s.begin(), s.end()
#define FOR(i, start, finish, k) for(int i = start; i <= finish; i += k)

const int MXN = 3e5 + 200;
const long long MNN = 5e3 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;
const int OO = 1e9 + 500;

typedef long long llong;
typedef unsigned long long ullong;

using namespace std;

string s;
vector<pair<int, int> > v;
vector<int> x;

void rec(int l, int r, int L, int R){
    if((r + l) % 2 == 0){
        if(s[(r + l) / 2] == '1'){
            int tm = (L + R) / 2;
            v.pb({L, tm + 1});
            rec(l, tm - 1, L, tm);
            rec(tm + 1, r, tm + 1, R);
        }else{
            int tm = (L + R) / 2;
            v.pb({L, tm});
            v.pb({tm, tm + 1});
            rec(l, tm - 1, L, tm - 1);
            rec(tm + 1, r, tm + 1, R);
        }
    }
}

int main () {
    ios;
    cin >> s;
    if(s[s.size() - 1] == '1') return cout << -1, 0;
    string t = "#";
    for(int i = 0; i < s.size() - 1; i++){
        t += s[i];
    }
    s = t;
    if(s[1] == '0') return cout << -1, 0;
    for(int i = 1; i < s.size() - 1; i++){
        if(s[i] != s[s.size() - i]){
            return cout << -1, 0;
        }
    }
    for(int i = 1; i < s.size(); i++){
        if(s[i] == '1') x.pb(i);
    }
    for(int i = 1; i < x.size(); i++){
        v.pb({x[i - 1], x[i]});
    }
    int batya = 0;
    for(int i = s.size() - 1; i >= 1; i--){
        if(s[i] == '1'){
            batya = i;
        }else{
            v.pb({batya, i});
        }
    }
    v.pb({s.size(), s.size() - 1});
    for(int i = 0; i < v.size(); i++){
        cout << v[i].F << ' ' << v[i].S << nl;
    }
    return 0;
}
