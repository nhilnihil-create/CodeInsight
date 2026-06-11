#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define N_MAX 200002

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

ll inv[N_MAX],fac[N_MAX],finv[N_MAX];

void init(){
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for(int i=2;i<N_MAX;i++){
        inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
        fac[i]=fac[i-1]*(ll) i%MOD;
        finv[i]=finv[i-1]*inv[i]%MOD;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    init();
    int N;
    ll A[100000];
    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];
    ll tmp = 0;
    for(int i = 0; i < N; i++){
        tmp += inv[i+1];
        tmp %= MOD;
    }
    ll ans = 0;
    ans += tmp*A[0];
    ans %= MOD;
    // cout << tmp << endl;
    for(int i = 1; i < N; i++){
        tmp -= inv[N-i+1];
        tmp %= MOD;
        tmp += MOD;
        tmp %= MOD;
        tmp += inv[i+1];
        tmp %= MOD;
        ans += tmp*A[i];
        ans %= MOD;
    }
    // cout << tmp << endl;
    // cout << ans << endl;
    cout << (fac[N]*ans)%MOD << endl;
}