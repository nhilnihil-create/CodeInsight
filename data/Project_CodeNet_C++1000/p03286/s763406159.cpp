#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,n) for(int i=(a); i<(n); i++)
#define all(v) v.begin(), v.end()
#define fi first
#define se second
#define sz(x) int(x.size())
using namespace std;
using ll = long long;
using P = pair<int ,int>;
const int INF = 1001001001;
const int MOD = 1000000007;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

#ifdef _DEBUG
#include "debug.h"
#else
#define debug(...)
#define print(...)
#endif

int main() {
    int n; cin >> n;
    if (n==0) {
        cout << 0 << endl;
        return 0;
    }
    vector<ll> a(60, 0);
    rep(i, 60) {
        a[i] += pow(-2, i);
        if (i<58) a[i+2] = a[i];
    }
    debug(a);
    int start;
    rep(i, 60) if (((a[i]>=0)==(n>=0))&&(abs(a[i])>=abs(n))) {
        start = i;
        break;
    }
    string s;
    for (ll i = start; i >= 0; i--) {
        if (i==start) {
            n -= pow(-2, i);
            s += '1';
        } else {
            ll x = pow(-2, i);
            ll y = x/4;
            debug(x, abs(n-x), abs(n), abs(y));
            // if (abs(n-x)<=abs(n) || (n==-1 && i==1)) {
            // if (abs(n)>=abs(y)) {
            if ((i>1&&(a[i]>=0)==(n>=0)&&abs(n)>abs(a[i-2]))||(abs(n-x)<=abs(n))||(n==-1&&i==1)) {
                n -= x;
                s += '1';
            } else {
                s += '0';
            }
        }
        debug(i, pow(-2, i), n, s);
    }

    cout << s << endl;
    // ll tmp = 0;
    // rep(i, sz(s)) {
    //     if (s[i]=='1') tmp += pow(-2, sz(s)-i-1);
    // }
    // cout << tmp << endl;
}