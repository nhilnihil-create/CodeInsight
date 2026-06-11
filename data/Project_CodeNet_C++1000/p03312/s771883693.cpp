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

const int MXN = 2e5 + 200;
const long long MNN = 5e3 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;
const int OO = 1e9 + 500;

typedef long long llong;
typedef unsigned long long ullong;

using namespace std;

int n, b[MXN];
llong pr[MXN];

llong dif(int l, int r, llong sum){
    llong x = pr[r] - pr[l - 1];
    sum -= x;
    return abs(sum - x);
}

llong ters(int L, int R){
    llong sum = pr[R] - pr[L - 1];
    int l = L, r = R - 1;
    while(r - l > 2){
        int tm1 = l + (r - l) / 3, tm2 = r - (r - l) / 3;
        if(dif(L, tm1, sum) <= dif(L, tm2, sum)){
            r = tm2;
        }else{
            l = tm1;
        }
    }
    //cout << "ternary " << l << ' ' << r << ' ';
    llong mn = INF, ans = 0;
    for(int i = l; i <= r; i++){
        llong x = dif(L, i, sum);
        //cout << i << ' ' << x << ' ';
        if(x < mn){
            mn = x;
            ans = i;
        }
    }
    //cout << nl;
    return ans;
}

int main () {
    ios;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> b[i];
        pr[i] = pr[i - 1] + b[i];
    }
    llong ans = INF;
    for(int i = 2; i <= n - 2; i++){
        llong L = ters(1, i);
        llong R = ters(i + 1, n);
        llong mx = max(max(pr[n] - pr[R], pr[R] - pr[i]), max(pr[i] - pr[L], pr[L] - pr[0]));
        llong mn = min(min(pr[n] - pr[R], pr[R] - pr[i]), min(pr[i] - pr[L], pr[L] - pr[0]));
        ans = min(mx - mn, ans);
    }
    cout << ans;
    return 0;
}
