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
    string S,T;
    cin >> S >> T;
    bool ok = true;
    int N = S.size();
    map<char,int> mp_S,mp_T;
    REP(i,N) {
        if(mp_S.count(S[i])) mp_S[S[i]]++;
        else  mp_S[S[i]] = 1;
        if(mp_T.count(T[i])) mp_T[T[i]]++;
        else  mp_T[T[i]] = 1;
    }
    veci A;
    veci B;
    for(auto p : mp_S) A.push_back(p.second);
    for(auto p : mp_T) B.push_back(p.second);
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    if(A.size() != B.size()) ok = false;
    else {
        REP(i,A.size()) if(A[i] != B[i]) ok = false;
    }
    cout << (ok ? "Yes" : "No") << endl;
}
