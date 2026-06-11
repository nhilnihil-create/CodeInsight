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

    string S; cin >> S;
    int N = S.size();

    int ans=N/2;
    if (N%2==1) {
        int k = N/2;    
        char c = S[k];
        int l = k, r = k;
        while(0<=l && r<N) {
            if (S[l]==c && S[r]==c) {
                l--; r++;
                k++;
            } else {
                break;
            }
        }
        ans = k;
    } else {
        int k = N/2;    
        char c = S[k];
        int l = k-1, r = k;
        while(0<=l && r<N) {
            if (S[l]==c && S[r]==c) {
                l--; r++;
                k++;
            } else {
                break;
            }
        }
        ans = k;
    }

    cout << ans << endl;

    return 0;
}