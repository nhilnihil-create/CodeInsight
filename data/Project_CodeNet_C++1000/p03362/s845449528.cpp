#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define ve vector
#define chmin(x,y) x = min(x,y)

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

int main(){
    int n;
    cin >> n;
    Sieve sv(55560);
    
    ve<int> ans;
    rep(i,55555){
        if(sv.isPrime((int)i+1)){
            if((i+1)%5==1) ans.push_back((int)i+1);
        }
        if(ans.size() == n)break;
    }
    rep(i,n-1)cout<<ans[i]<<" ";
    cout<<ans[n-1]<<endl;
    return 0;
}
