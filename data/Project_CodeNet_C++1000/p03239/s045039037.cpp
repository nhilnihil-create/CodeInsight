//url:
//problem name: 

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
    int N,T; cin >> N >> T;
    vector<P> A(N);
    REP(i,N) cin >> A[i].first >> A[i].second;
    int ans = 1e9;;
    REP(i,N) if(A[i].second <= T) {
        chmin(ans,A[i].first);
    }
    if(ans == 1e9) cout <<"TLE" << endl;
    else cout << ans << endl;
}
