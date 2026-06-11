#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
template <class T>inline bool chmin(T &a, T b){if (a > b){a = b;return true;}return false;}
template <class T>inline bool chmax(T &a, T b){if (a < b){a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Pl = pair<long long, long long>;
using veci = vector<int>;
using vecl = vector<long long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

ll gcd(ll a, ll b) {
    if(b == 0) return a;
    else return gcd(b,a%b);
}

int main() {
    int N;
    cin >> N;
    vecl A(N),B(N);
    REP(i,N) cin >> A[i];
    B = A;
    reverse(B.begin(),B.end());
    vecl R(N+1),L(N+1);
    REP(i,N) {
        R[i+1] = gcd(R[i],A[i]);
        L[i+1] = gcd(L[i],B[i]);
    }
    ll ans = 0;
    REP(i,N) {
        chmax(ans,gcd(L[i],R[N-1-i]));
    }
    cout << ans << endl;
}