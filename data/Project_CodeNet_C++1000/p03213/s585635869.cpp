#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define ve vector

struct Sieve{
    int n;
    vector<int> f,primes;
    Sieve(int n = 1):n(n), f(n+1) {
        f[0] = f[1] = -1;
        for(ll i = 2;i <= n; i++){
            if(f[i])continue;
            primes.push_back(i);
            f[i] = i;
            for(ll j = i * 2; j <= n; j += i){
                if(!f[j])f[j] = i;
            }
        }
    }
    bool isPrime(int x){return f[x] == x;}
    vector<int> factorList(int x){
        vector<int> res;
        while(x != 1){
            res.push_back(f[x]);
            x /= f[x];
        }
        return res;
    }
    vector<P> factor(int x){
        vector<int> fl = factorList(x);
        if(fl.size() == 0) return {};
        vector<P> res(1,P(fl[0],0));
        for(int p: fl){
            if(res.back().first == p){
                res.back().second++;
            }else{
                res.emplace_back(p,1);
            }
        }
        return res;
    }
};

int main() {
    ll n;
    cin >> n;
    if(n<10){
        cout << 0 << endl;
        return 0;
    }
    map<ll,ll> mp;
    Sieve s(110);
    for (int i=2; i<=n; i++) {
        if(s.isPrime(i)) mp[i] = 1;
        else{
            ve<P> f = s.factor(i);
            for(P x: f){
                mp[x.first] += x.second;
            }
        }
    }
    ll ans = 0;
    ll u2=0, u4=0,u14=0,u24=0,u74=0;
    for(P x:mp){
        ll cnt = x.second;
        if(cnt>=74){
            u2++;u4++;u14++;u24++;u74++;
            continue;
        }if(cnt>=24){
            u2++;u4++;u14++;u24++;
            continue;
        }if(cnt>=14){
            u2++;u4++;u14++;
            continue;
        }if(cnt>=4){
            u2++;u4++;
            continue;
        }if(cnt>=2)u2++;
    }
    ans += (u4*(u4-1)*(u2-2))/2;
    ans += u74;
    ans += u24*(u2-1);
    ans += u14*(u4-1);
    cout << ans << endl;
    return 0;
}
