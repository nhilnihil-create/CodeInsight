#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1000000009LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define fo(i,j,n) for (int i=(j); i < (n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    int n; cin >> n;
    vector<ll> A(n); rep(i, n) cin >> A[i];

    sort(all(A));
    ll ans[2] = {A[n-1], -1};
    ll half = ans[0]/ 2;
    rep(i, n){
        ll num = A[i];
        if(num <= half)
            chmax(ans[1], num);
        else{
            ll tmp = ans[0] - num;
            if(ans[1] < tmp) ans[1] = num;  
            break;
        }
    }

    cout << ans[0] << " " << ans[1] << ln;
}

    