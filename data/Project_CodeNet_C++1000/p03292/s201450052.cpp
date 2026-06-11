#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long long,long long>;
using veci = vector<int>;
using vecl = vector<long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

int main() {
    veci A(3);
    REP(i,3) cin >> A[i];
    int ans = 1e5;
    REP(i,3) REP(j,3) REP(k,3) {
        if(i == j || j == k || i == k) continue;
        chmin(ans,abs(A[i]-A[j])+abs(A[j]-A[k]));
    }
    cout << ans << endl;
}