#ifdef _DEBUG
#include "MyLib.h"
#else
#define main_D main
#include "bits/stdc++.h" 
#include <regex>
#define _USE_MATH_DEFINES
#include <math.h>
#define FOR(i,s,e) for (int i = int(s); i < int(e); ++i)
#define REP(i,e) FOR(i,0,e)
#define INF (INT_MAX/2)
#define EPS (1.0e-8)
#define LINF (LLONG_MAX/2)
const int MGN = 8;
const int ARY_SZ_MAX = 10000000;
using namespace std;
using ll = long long; using ull = unsigned long long;
using vi = vector<int>; using vvi = vector<vi>; using vvvi = vector<vvi>;
using vb = vector<bool>; using vvb = vector<vb>; using vvvb = vector<vvb>;
using vl = vector<ll>; using vvl = vector<vl>;
using vd = vector<double>; using vs = vector<string>;
using pii = pair<int, int>; using pll = pair<ll, ll>;
// functions

#endif


int main_D() {
    cin.tie(0);
    ios::sync_with_stdio(false);


    int K; cin >> K;

    vvi es(K);
    map<pii, int> cost;
    REP(i,K) {
        int j = (i + 1) % K;
        es[i].push_back(j);
        cost[pii(i, j)] = 1;
        int k = (i * 10) % K;
        es[i].push_back(k);
        cost[pii(i, k)] = 0;
    }

    deque<int> dq;
    dq.push_back(1);
    vi dist(K, INF);
    dist[1] = 0;
    vb vis(K, false);
    while(!dq.empty()) {
        int x = dq.front(); dq.pop_front();
        vis[x] = true;

        for(int nx : es[x]) {
            if (vis[nx]) continue;

            if (cost[pii(x,nx)]==0) {
                dq.push_front(nx);
                dist[nx] = dist[x];
            } else if (cost[pii(x,nx)]==1) {
                dq.push_back(nx);
                dist[nx] = dist[x] + 1;
            }
        }
    }

    int ans = dist[0] + 1;
    cout << ans << endl;


    return 0;
}