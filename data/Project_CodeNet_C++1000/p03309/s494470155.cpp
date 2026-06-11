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
    int N;
    cin >> N;
    vecl A(N);
    REP(i,N) {
        ll a; cin >> a;
        A[i] = a - (i+1);
    }
    sort(A.begin(),A.end());
    ll b;
    if(N%2 != 0) b = A[N/2];
    else b = (A[N/2-1]+A[N/2])/2;
    ll ans = 0;
    REP(i,N) ans += abs(A[i]-b);
    cout << ans << endl;
}