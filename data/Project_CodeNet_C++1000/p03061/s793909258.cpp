#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e15;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// __uint128_t
const ll MOD = 2019;


//最大公約数
ll gcd(ll a, ll b) {
    return b ? gcd(b, a%b) : a;
}


int main(){
    ll N; cin >> N;
    vector<ll> A(N); rep(i, N) cin >> A[i];
    vector<ll> GCDL(N), GCDR(N); GCDL[0] = A[0], GCDR[N-1] = A[N-1];
    ll ans = 0;
    for(int i = 1; i < N; i++) GCDL[i] = gcd(GCDL[i-1], A[i]);
    for(int i = N-2; i >= 0; i--) GCDR[i] = gcd(GCDR[i+1], A[i]);

    for(int i = 0; i < N; i++){
        if(i == 0) ans = max(ans, GCDR[1]);
        else if(i == N-1) ans = max(ans, GCDL[N-2]);
        else ans = max(ans, gcd(GCDL[i-1], GCDR[i+1]));
    }
    cout << ans << endl;

}