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


    int N; cin >> N;
    vi A(N); REP(i, N) cin >> A[i];

    vector<pii> B;
    REP(i, N) B.push_back(pii(A[i], i));    
    sort(B.begin(), B.end());

    int lo = B[0].first, hi = B[N - 1].first;

    vector<pii> ans;
    if (lo >= 0) {
        for(int i=0; i<N-1; i++) {
            A[i + 1] += A[i];
            ans.push_back(pii(i + 1, i + 2));
        }
    } else if (hi <= 0) {
        for(int i=N-1; i>=1; i--) {
            A[i - 1] += A[i];
            ans.push_back(pii(i + 1, i));
        }
    } else {
        if (abs(lo) < abs(hi)) {
            int hiIdx = B[N - 1].second;
            REP(i,N) {
                if (i == hiIdx) continue;
                A[i] += hi;
                ans.push_back(pii(hiIdx + 1, i + 1));
            }

            for(int i=0; i<N-1; i++) {
                A[i + 1] += A[i];
                ans.push_back(pii(i + 1, i + 2));
            }
        } else {
            int loIdx = B[0].second;
            REP(i,N) {
                if (i == loIdx) continue;
                A[i] += lo;
                ans.push_back(pii(loIdx + 1, i + 1));
            }

            for(int i=N-1; i>=1; i--) {
                A[i - 1] += A[i];
                ans.push_back(pii(i + 1, i));
            }
        }
    }

    cout << ans.size() << endl;
    for(auto p : ans) {
        cout << p.first << " " << p.second << endl;
    }


    return 0;
}