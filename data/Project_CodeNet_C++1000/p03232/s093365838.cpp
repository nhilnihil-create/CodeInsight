#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>
#include<climits>
#include<cstdlib>
#include<cmath>
#include<string>
#include<iomanip>
#include<bitset>

using namespace std;

#define ll long long int

ll const MOD = 1000000007;
ll const INF = (long long int)1 << 61;

ll mypow(ll x,ll n){
    ll ret = 1;
    while(n > 0){
        if(n&1) ret = (ret * x)%MOD;
        x = (x*x)%MOD;
        n >>= 1;
    }
    return ret;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll n;
    cin >> n;

    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<ll> sum(n+1,0);

    ll factorial = 1;

    for(ll k = 1; k < n+1; k++){
        factorial = (factorial * k)%MOD;
        sum[k] = (sum[k-1] + mypow(k,MOD-2))%MOD;
    }

    ll ans = 0;

    for(ll k = 0; k < n; k++){
        ll p = (sum[k+1] + sum[n-k])%MOD;
        p = (p + (MOD - 1))%MOD;
        p = (p * factorial)%MOD;
        ans = (ans + (p * a[k])%MOD )%MOD;
    }

    cout << ans << endl;
    
    return 0;
}