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
    vd V(N); REP(i, N) cin >> V[i];

    int TSum = 0;
    REP(i, N) TSum += T[i];
    TSum *= 2;

    vd vMax(TSum+MGN,0);
    vMax[0] = 0; // Begin
    vMax[TSum] = 0; // End
    for(int t=1; t<TSum; t++) {
        vMax[t] = LINF;
    }

    int now = 0;
    REP(i,N) {
        int next = now + T[i] * 2;
        for (int t = now; t <= next; t++) {
            vMax[t] = min(vMax[t], V[i]);
        }
        now = next;
    }

    for (int t = 1; t <= TSum; t++) {
        vMax[t] = min(vMax[t - 1] + 0.5, vMax[t]);
    }
    for(int t = TSum-1; t >= 0; t--) {
        vMax[t] = min(vMax[t + 1] + 0.5, vMax[t]);
    }

    double ans = 0;
    for(int t=0; t<TSum; t++) {
        ans += 0.5 * (vMax[t] + vMax[t + 1]) / 2; // Trapezoid
    }

    cout << fixed << setprecision(15) << ans << endl;


    return 0;
}