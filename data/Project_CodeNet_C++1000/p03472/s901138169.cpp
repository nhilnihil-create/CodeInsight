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
using vecl = vector<long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

int main() {
    int N;
    ll H;
    cin >> N >> H;
    vecl A(N),B(N);
    ll ans = 0;
    REP(i,N) cin >> A[i] >> B[i];
    sort(B.begin(),B.end(),greater<ll>());
    sort(A.begin(),A.end(),greater<ll>());
    REP(i,N) {
        if(A[0] <= B[i]) {H -= B[i];
        ans++;}
        if(H <= 0) {
            cout << ans << endl;
            return 0;
        }
    }
    ans += H/A[0] + (H%A[0] == 0 ? 0 : 1);
    cout << ans << endl;
}
