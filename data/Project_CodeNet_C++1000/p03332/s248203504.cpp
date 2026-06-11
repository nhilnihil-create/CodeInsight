#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end() //使うときはsort(all())という感じで
#define PI 3.14159265359

using ll = long long;

#define NNE 998244353

vector<ll> facto_n(300001); // nCkの計算用 facto_n[n_i]には(n_i)!が
vector<ll> facto_n_pow(300001); // nCkの計算用 facto_n_pow[n_j]には(n_j)!^(NNE-2)が

ll nnepow(ll x, ll n){ 
    ll ans = 1;
    while(n != 0){
        if(n&1) ans = ans*x % NNE;
        x = x*x % NNE;
        n = n >> 1;
    }
    return ans;
}

ll combi(ll a, ll b){
    if(a==0 && b==0){
        return 1;
    }
    if(a < b || a < 0 || b < 0){
        return 0;
    }
    ll ans = ( (facto_n[a] * facto_n_pow[b]) % NNE ) * facto_n_pow[a-b] % NNE;
    return ans;
}

int main() {
    ll n,a,b,k;
    cin >> n >> a >> b >> k;
    facto_n[0] = 1;
    facto_n_pow[0] = 1;
    rep(i,n){
        facto_n[i+1] = facto_n[i]*(i+1) % NNE;
        facto_n_pow[i+1] = facto_n_pow[i]*nnepow((i+1),NNE-2) % NNE;  
    }
    ll ans = 0;
    rep(i,n+1){
        if((k-i*a)%b == 0){
            if(((k-i*a)/b)>=0 && ((k-i*a)/b) <=n){
                ll n_a = i;
                ll n_b = (k-i*a)/b;
                ans += combi(n,n_a) * combi(n,n_b) % NNE;
            }
        }
    }
    cout << ans % NNE << endl;
    return 0;
}