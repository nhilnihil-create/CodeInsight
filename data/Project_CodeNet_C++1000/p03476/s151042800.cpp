#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
const int inf = 1001001001;
 
int main(){

    ll max=101010;
    vector<ll> is_prime(max,1);
    is_prime[0]=0;
    is_prime[1]=0;
    for(ll i=2; i<max; i++){
        if(!is_prime[i]) continue;
        for(ll j=i*2; j<max; j+=i) is_prime[j]=0;
    }

    vector<ll> a(max,0);
    for(ll i=0; i<max; i++){
        if(i%2==0) continue;
        if(is_prime[i] && is_prime[(i+1)/2]) a[i]=1;
    }

    vector<ll> dp(max+1,0);
    for(ll i=0; i<max; i++) dp[i+1]=dp[i]+a[i];

    ll Q;
    cin >> Q;
    rep(q,Q){
        int l,r;
        cin >> l >> r;
        cout << dp[r+1]-dp[l] << endl;
    }



 
}