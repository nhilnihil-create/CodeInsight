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

void printvec(vecl A) {
    REP(i,A.size()) cout << A[i] << " ";
    cout << endl;
}

void solve(vecl A, vecl B, int N) {
    ll sumA = 0, sumB = 0;
    REP(i,N) sumA += A[i];
    REP(i,N) sumB += B[i];
    if(sumA > sumB) {
        cout << "No" << endl;
        return;
    }
    
    ll cntA = 0,cntB = 0;

    REP(i,N) {
        if(A[i] > B[i]) cntB += A[i]-B[i];
        else if(A[i] < B[i]) cntA += (B[i]-A[i])/2; 
    }
    if(cntA >= cntB) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main() {

    // 入力
    int N; cin >> N;
    vecl A(N),B(N);
    REP(i,N) cin >> A[i];
    REP(i,N) cin >> B[i];

    //solve
    solve(A,B,N);

}