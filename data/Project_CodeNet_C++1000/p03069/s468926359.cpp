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

int main() {
    int N; cin >> N;
    string S; cin >> S;
    veci cumW(N+1),cumB(N+1);
    REP(i,N) {
        if(S[i] == '#') {
            cumB[i+1] = cumB[i] + 1;
            cumW[i+1] = cumW[i];
        } 
        else {
            cumW[i+1] = cumW[i]+1;
            cumB[i+1] = cumB[i];
        } 
    }
    int ans = 1e9;
    for(int i = 0; i <= N; i++) {
        //cout << cumB[i]+cumW[N]-cumW[i] << endl;
        chmin(ans,cumB[i]+cumW[N]-cumW[i]);
    }
    cout << ans << endl;
}