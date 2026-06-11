#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;

vector<pair<ll,ll>> prime_factorize(ll N){
    vector<pair<ll,ll>> res;
    for(ll i=2;i*i<=N;i++){
        if(N%i!=0) continue;
        ll ex=0;
        while(N%i==0){
            ex++;
            N/=i;
        }
        res.push_back({i,ex});
    }
    if(N!=1)res.push_back({N,1});
    return res;
}

int main() {
    ll n,p;
    cin >> n >> p;
    vector<pair<ll,ll>>num=prime_factorize(p);
    ll ans=1;
    for(auto x:num){
        ll ex=x.second;
        while(ex>=n){
            ans*=x.first;
            ex-=n;
        }
    }
    cout << ans << endl;
}