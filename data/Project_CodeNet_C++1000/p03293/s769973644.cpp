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
    string S,T; cin >> S >> T;
    int N = S.size();
    REP(i,N) {
        string A = "";
        A += S[N-1];
        REP(j,N-1) {
            A += S[j];
        }
        //cout << A << endl;
        if(A == T) {
            cout << "Yes" << endl;
            return 0;
        }
        S = A;
    }
    cout << "No" << endl;
}