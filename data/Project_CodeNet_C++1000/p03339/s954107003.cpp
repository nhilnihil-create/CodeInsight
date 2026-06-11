//url:
//problem name: Brick Break

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
    int N; cin >> N;
    string S; cin >> S;
    vecl E(N+1);
    vecl W(N+1);
    REP(i,N) {
        if(S[i] == 'W') {
            W[i+1] = W[i] + 1;
            E[i+1] = E[i];
        }
        else {
            E[i+1] = E[i] + 1;
            W[i+1] = W[i];
        }
    }
    /*
    REP(i,N+1) {
        cout << E[i] << " " << W[i] << endl;
    }
    */
    ll ans = 1e9;
    REP(i,N) {
        ll res;
        if(i == 0) res = E[N] - E[1];
        else if(i == N-1) res = W[N-2]-W[0];
        else res = (W[i]-W[0])+(E[N]-E[i+1]);
        //cout << res << endl;
        chmin(ans,res);
    }
    cout << ans << endl;
}