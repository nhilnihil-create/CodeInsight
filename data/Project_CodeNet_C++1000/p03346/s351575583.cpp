#include <bits/stdc++.h>
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define reprrev(i,a,b) for(int i=b-1;i>=a;i--) // [a, b)
#define reprev(i,n) reprrev(i,0,n)
typedef long long ll;
typedef unsigned long long ull;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const ll mod = 1e9+7;


void chmod(ll &M){
    if(M >= mod) M %= mod;
    else if(M < 0){
        M += (abs(M)/mod + 1)*mod;
        M %= mod;
    }
}

ll modpow(ll x, ll n){
    if(n==0) return 1;
    ll res=modpow(x, n/2);

    if(n%2==0) return res*res%mod;
    else return res*res%mod*x%mod;
}

int getl(int i, int N) { return i==0? N-1:i-1; };
int getr(int i, int N) { return i==N-1? 0:i+1; };

// 線分 ab の偏角 返り値は[-π, π]
double argument(const pair<double, double> &a, const pair<double, double> &b){
    double ax=a.first, ay=a.second, bx=b.first, by=b.second;
    return atan2(by-ay, bx-ax);
}

/* <-----------------------------------------------------------------------------------> */
/* <-----------------------------------------------------------------------------------> */
/* <-----------------------------------------------------------------------------------> */
/* <-----------------------------------------------------------------------------------> */
/* <-----------------------------------------------------------------------------------> */
/* <-----------------------------------------------------------------------------------> */
/* <-----------------------------------------------------------------------------------> */
/* <-----------------------------------------------------------------------------------> */

/* 注意 

    1LL<<60 * N とかのオーバーフローに気を付けろ
    制約がヒントになる、ちゃんと全ての制約を見ろ

*/

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; std::cin >> n;
    std::vector<int> p(n);
    rep(i, n) cin >> p[i];
    std::vector<int> dp(n+1, 0);
    int ans = 0;
    rep(i, n) { dp[p[i]] = dp[p[i]-1]+1; ans = std::max(ans, dp[p[i]]); }
    std::cout << n-ans << std::endl;
    
    
    return 0;
}