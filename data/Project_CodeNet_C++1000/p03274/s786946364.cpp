#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Pl = pair<long long, long long>;
using veci = vector<int>;
using vecl = vector<long long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

int main() {
    int N,K; cin >> N >> K;
    vecl A(N); REP(i,N) cin >> A[i];
    ll ans = 1LL << 60;
    for(int i = 0; i <= N-K; i++) {
        //cout << A[i] << " " << A[i+K-1] << endl;
        if(A[i] > 0 && A[i+K-1] > 0) chmin(ans,A[i+K-1]);
        else if(A[i] < 0 && A[i+K-1] < 0) chmin(ans,-A[i]);
        else if(abs(A[i]) >= abs(A[i+K-1])) chmin(ans,2*abs(A[i+K-1])+abs(A[i]));
        else chmin(ans,2*abs(A[i])+abs(A[i+K-1]));
    }
    cout << ans << endl;
}
