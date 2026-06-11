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
using psi = pair<string, int>;
// functions

#endif


int main_D() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int A, B; cin >> A >> B;
    int W = 100, H = 100;

    vs s(H);
    REP(i, H / 2) s[i] = string(W, '.');
    FOR(i, H / 2, H) s[i] = string(W, '#');

    int cnt = 1;
    bool ok = false;
    for(int i= 0; i<H/2; i+=2) {
        for(int j=0; j<W; j+=2){
            if (cnt >= B) {
                ok = true;
                break;
            }
            s[i][j] = '#';
            cnt++;
        }
        if (ok) break;
    }

    cnt = 1;
    ok = false;
    for(int i= H/2+1; i<H; i+=2) {
        for(int j=0; j<W; j+=2){
            if (cnt >= A) {
                ok = true;
                break;
            }
            s[i][j] = '.';
            cnt++;
        }
        if (ok) break;
    }

    cout << H << " " << W << endl;
    REP(i,H) {
        cout << s[i] << endl;
    }

    return 0;
}