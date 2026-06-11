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

const int MXN = 1e5 + 200;
const long long MNN = 5e3 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;
const long long OO = 1e9 + 500;

typedef long long llong;
typedef unsigned long long ullong;

using namespace std;

llong m, k;

int main () {
    ios;
    cin >> m >> k;
    llong xr = 0;
    if(k == 0){
        for(int i = 0; i < (1 << m); i++){
            cout << i << ' ' << i << ' ';
        }
        return 0;
    }
    if(k > (1 << m)){
        cout << -1;
        return 0;
    }
    for(int i = 0; i < (1 << m); i++){
        if(k == i) continue;
        xr ^= i;
    }
    if(xr != k) return cout << -1, 0;
    for(int i = 0; i < (1 << m); i++){
        if(k == i) continue;
        cout << i << ' ';
    }
    cout << k << ' ';
    for(int i = (1 << m) - 1; i >= 0; i--){
        if(k == i) continue;
        cout << i << ' ';
    }
    cout << k;
    return 0;
}
