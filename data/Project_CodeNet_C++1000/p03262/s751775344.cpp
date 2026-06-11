#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define pb push_back
#define ALL(v) v.begin(),v.end()
const long long INF = 1LL << 60; // 仮想的な無限大の値;
using namespace std;
using ll = long long;
using P = pair<int, int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;
ll gcd(ll a, ll b)
{
    if(b == 0) return a;
    return gcd(b, a%b);
}
int main()
{
    ll N, X;
    cin >> N >> X;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    A.pb(X);
    sort(ALL(A));

    vector<ll> B(N);
    rep(i, N)
    {
        B[i] = A[i+1]-A[i];
    }
    ll ans = 0;
    rep(i, N)
    {
        ans = gcd(B[i], ans);
    }
    cout << ans  << endl;

    return 0;
}