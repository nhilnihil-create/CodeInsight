#include <iostream>
using namespace std;
long long mod = 1000000007,inv[100010],f[100010],a[100010],ans = 0,res = 0;
void solve(){
    inv[1] = 1; f[1] = 1;
    for(int i=2;i<=100000;i++){
        inv[i] = mod - (mod/i)*inv[mod%i]%mod;
        f[i] = f[i-1]*i%mod;
    }
}

int main(){
    int i,n;
    cin >> n;
    solve();
    for(i=1;i<=n;i++){
        cin >> a[i];
        (res += inv[i]) %= mod;
    }
    ans = res*a[1]%mod;
    for(i=2;i<=n;i++){
        (res += (inv[i] - inv[n + 2 -i] + mod)%mod) %= mod;
        (ans += res*a[i]) %= mod;
    }
    (ans *= f[n]) %= mod;
    cout << ans << endl;
}