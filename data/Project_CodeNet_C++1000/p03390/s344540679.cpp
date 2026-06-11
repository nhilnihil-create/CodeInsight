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

const int MXN = 2e5 + 1;
const long long MNN = 5e3 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;
const int OO = 1e9 + 500;

typedef long long llong;
typedef unsigned long long ullong;

using namespace std;

int n;
int t, q;

int main () {
    cin >> q;
    while(q--){
        llong a, b;
        cin >> a >> b;
        llong sq = sqrt(a * b);
        llong k = sq;
        if(sq * sq == a * b){
            sq --;
        }
        llong ans = sq * 2;
        if(sq != 0){
            if((a * b - 1) / sq == sq){
                ans--;
            }
        }
        if(a <= sq){
            ans--;
        }if(b <= sq){
            ans--;
        }
        cout << ans << nl;
    }
    return 0;
}
