#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
//---------------------------------------------------------------------------------------------------
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧  
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     
　　　　／　　　＼　 　 |　|     
　　　 /　　 /￣￣￣￣/　　|  
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿  
　 　　　＼/＿＿＿＿/　（u　⊃  
---------------------------------------------------------------------------------------------------*/



ll mul(ll a, ll b) {
    // infl < ab
    if (infl / a<b) return infl;
    return min(infl, a*b);
}


int N, X, A[201010];
ll B[201010];
//---------------------------------------------------------------------------------------------------
ll get(int a, int b) {
    ll res = B[b];
    if (a) res -= B[a - 1];
    return res;
}
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> X;
    rep(i, 0, N) cin >> A[i];
    B[0] = A[0];
    rep(i, 0, N) B[i] = B[i - 1] + A[i];

    ll ans = infl;
    rep(k, 1, N + 1) {
        ll sm = 0;
        int R = N - 1;
        ll p = 5;
        while (0 <= R) {
            int L;
            if (R == N - 1) L = R - 2 * k + 1;
            else L = R - k + 1;
            L = max(L, 0);

            sm = min(infl, sm + get(L, R) * p);
            
            R = L - 1;
            p += 2;
        }
        sm = min(infl, sm + 1LL * X * (N + k));
        chmin(ans, sm);
    }

    cout << ans << endl;
}