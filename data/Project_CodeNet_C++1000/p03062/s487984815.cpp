#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long,long>;
using veci = vector<int>;
using vecl = vector<long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

ll INF = 1LL << 60;

int main() {
    int N; cin >> N;
    vecl A(N); REP(i,N) cin >> A[i];
    int cnt = 0;
    int p;
    ll cur = INF;
    REP(i,N) {
        if(A[i] < 0) cnt++;
        if(abs(A[i]-0) <= cur) {
            p = i;
            cur = abs(A[i]);
        }
    }
    //cout << cur << endl;
    ll ans = 0;
    if(cnt%2 == 0) REP(i,N) ans += abs(A[i]);
    else {
        REP(i,N) if(i == p) ans -= abs(A[i]); else ans += abs(A[i]);
    }
    cout << ans << endl;
}

