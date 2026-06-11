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
#define no_answer return cout << "NO", 0;
#define FOR(i, start, finish, k) for(int i = start; i <= finish; i += k)

const int MXN = 2e5 + 200;
const long long MNN = 3e3 + 200;
const long long MOD = 1e9 + 7;
const long long INF = 1e13;
const int OO = 1e9 + 500;

typedef long long llong;
typedef unsigned long long ullong;

using namespace std;

int n, dp[MXN];
vector<int> q[MXN];
vector<int> v[MXN];
int dm = 0, pos = 0;

void dfs(int x, int p, int d){
    if(d > dm) dm = d, pos = x;
    for(int i = 0; i < q[x].size(); i++){
        if(q[x][i] != p){
            dfs(q[x][i], x, d + 1);
        }
    }
}

int main() {
    cin >> n;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        q[u].pb(v);
        q[v].pb(u);
    }
    dfs(1, 0, 0);
    dfs(pos, 0, 0);
    dm++;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 0;
    for(int i = 3; i <= dm; i++){
        dp[i] = !(dp[i - 2] & dp[i - 1]);
    }
    cout << (dp[dm] == 1 ? "First" : "Second");
}
