#include <iostream>
#define MOD 1000000007
#define SIZE 100001
using namespace std;
typedef long long ll;
ll Mp(ll a, ll b){
    ll res = 1;
    while(b > 0){
        if(b%2 == 0){
            a = (a * a) % MOD;
            b /= 2;
        }else{
            res = (res * a) % MOD;
            b--;
        }
    }
    return res;
}
int main(void){
    int n;
    ll ans = 0, nf = 1, fs[SIZE];
    cin >> n;
    fs[0] = 0;
    for(int i=1;i<=n;i++){
        nf = (nf * i) % MOD;
        fs[i] = (fs[i-1] + Mp(i, MOD-2)) % MOD;
    }
    for(int i=1;i<=n;i++){
        ll a, t = MOD-1;
        cin >> a;
        t += fs[i] + fs[n-i+1];
        t = (t%MOD * nf) % MOD;
        ans = (ans + a*t)%MOD;
    }
    cout << ans << endl;
}
