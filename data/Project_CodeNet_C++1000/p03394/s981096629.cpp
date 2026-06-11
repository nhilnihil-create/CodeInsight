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

const long long MXN = 1e5 + 1;
const long long MNN = 1e2 + 1;
const long long MOD = 998244353;
const long long INF = 1e18;
const long long OO = 1e9 + 500;

typedef long long llong;
typedef unsigned long long ullong;

using namespace std;

llong n, b[MXN];

int main(){
    ios;
    //    freopen("B.in", "r", stdin);
    //    freopen("B.out", "w", stdout);
    cin >> n;
    if(n == 3){
        cout << 2 << ' ' << 5 << ' ' << 63 << ' ';
        return 0;
    }
    llong x = 3;
    for( ; x + 6 <= 30000 && n >= 4; x += 12, n -= 2){
        cout << x << ' ' << x + 6 << ' ';
    }
    x = 2;
    for( ; n >= 3; x += 6, n -= 3){
        cout << x << ' ' << x + 2 << ' ' << x + 4 << ' ';
    }
    if(n == 1){
        cout << x + 4;
    }if(n == 2){
        cout << x << ' ' << x + 2;
    }
    return 0;
}
