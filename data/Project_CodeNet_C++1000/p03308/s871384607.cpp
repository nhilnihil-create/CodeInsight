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
    veci A(N);
    REP(i,N) cin >> A[i];
    int ans = 0;
    for(int i = 0; i < N-1; i++) {
        for(int j = i+1; j < N; j++) {
            chmax(ans,abs(A[i]-A[j]));
        } 
    }
    cout << ans << endl;
}