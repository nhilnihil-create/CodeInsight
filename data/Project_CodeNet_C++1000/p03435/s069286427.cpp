#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long long,long long>;
using veci = vector<int>;
using vecl = vector<long long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;
const int MOD = 1000000007;
const double pi = acos(-1);

int main() {
    vecveci C(3,veci(3));
    REP(i,3) REP(j,3) cin >> C[i][j];
    REP(a1,101) REP(a2,101) REP(a3,101) {
        bool ok = true;
        bool b1 = (C[0][0]-a1 == C[1][0]-a2) && (C[1][0]-a2 == C[2][0] - a3);
        bool b2 = (C[0][1]-a1 == C[1][1]-a2) && (C[1][1]-a2 == C[2][1] - a3);
        bool b3 = (C[0][2]-a1 == C[1][2]-a2) && (C[1][2]-a2 == C[2][2] - a3);
        if(b1 && b2 && b3) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
