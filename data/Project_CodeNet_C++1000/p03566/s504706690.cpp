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


    int N;  cin >> N;
    vi T(N); REP(i, N) cin >> T[i];
    vi V(N); REP(i, N) cin >> V[i];

    vi ts(N+1, 0);
    ts[0] = 0;
    FOR(i, 1, N+1) ts[i] = ts[i - 1] + T[i - 1];

    const int TMAX = N*200;
    vi v(TMAX, INF);
    vi vMax(TMAX,INF);

    int End = ts[N];
    vMax[0] = 0;
    vMax[End] = 0;
    REP(i,N) {
        for (int t=ts[i]; t<=ts[i+1]; t++) {
            vMax[t] = min(vMax[t], V[i]);
        }

        for(int t=ts[i]; t<ts[i+1]; t++) {
            v[t] = V[i];
        }
    }

    for(int t = 1; t < End; t++){
        vMax[t] = min(vMax[t], vMax[t-1]+1);
    }

    for(int t = End-1; t >= 1; t--){
        vMax[t] = min(vMax[t], vMax[t+1]+1);
    }

    double ans = 0.0;
    for(int t = 1; t <= End; t++){
        if (vMax[t] != vMax[t-1]) {
            ans += ((double)(vMax[t-1] + vMax[t]))/2.0;
        } else {
            if (vMax[t] == v[t-1]) { // move at the max speed 
                ans += vMax[t];
            } else { // accelerate or decelerate the speed
                ans += vMax[t] + 0.25;
            }
        }
    }

    cout << fixed << setprecision(15) << ans << endl;


    return 0;
}