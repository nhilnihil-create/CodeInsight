#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;

vector<ll> num(45,0);

//繰り返し二乗法
ll EX(ll x,ll n){
    if(n == 0) return 1;
    else if(n%2 == 1) return EX(x,n-1)*x;
    else return EX(x*x,n/2);
};

vector<ll> to_k (ll n,ll k){
    vector<ll> memo(45);
    for(ll i = 44; i >= 0; i--){
        ll e = EX(k,i);
        if(e <= n){
            memo[i] = 1;
            n -= e;
        } else memo[i] = 0;
    }
    return memo;
}
vector<ll> x(45);
ll re_k (ll k){
    ll res = 0;
    for(ll i = 0; i < 45; i++){
        res += x[i]*EX(k,i);
    }
    return res;
}

int main(){
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        vector<ll> vlu = to_k(a[i],2);
        for(ll j = 0; j < 45; j++){
            if(vlu[j] == 1) num[j]++;
        }
    }
    for(ll i = 0; i < 45; i++){
        if(num[i] <= n/2) x[i] = 1;
        else x[i] = 0;
    }
    vector<ll> kd = to_k(k,2);
    bool flag = true;
    for(int i = 44; i >= 0; i--){
        if(flag && kd[i] == 1) flag = false;
        if(kd[i] == 1 && x[i] == 0) break;
        else if(kd[i] == 0 || flag) x[i] = 0;
        
    }
    ll X = re_k(2);
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        ans += X^a[i];
    }
    cout << ans << endl;
    return 0;
}
