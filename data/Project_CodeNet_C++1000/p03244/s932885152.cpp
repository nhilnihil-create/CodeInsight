#include <bits/stdc++.h>
#include <fstream>
using namespace std;
typedef long long lint;
#define rep(i,n) for(lint (i)=0;(i)<(n);(i)++)
#define repp(i,m,n) for(lint (i)=(m);(i)<(n);(i)++)
#define repm(i,n) for(lint (i)=(n-1);(i)>=0;(i)--)
#define INF (1ll<<60)
#define all(x) (x).begin(),(x).end()
const lint MOD =1000000007;
const lint MAX = 1000000;
using Graph =vector<vector<lint>>;
typedef pair<lint,lint> P;
typedef map<lint,lint> M;
 
lint fac[MAX], finv[MAX], inv[MAX];
 
void COMinit() 
{
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (lint i = 2; i < MAX; i++)
    {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
 
long long COM(lint n, lint k)
{
    if (n < k)
        return 0;
    if (n < 0 || k < 0)
        return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
 
lint primary(lint num)
{
    if (num < 2) return 0;
    else if (num == 2) return 1;
    else if (num % 2 == 0) return 0;
 
    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
 
    return 1;
}
   long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
    lint lcm(lint a,lint b){
        return a/__gcd(a,b)*b;
    }
     lint gcd(lint a,lint b){
        return __gcd(a,b);
    } 
    
    
  int main(){
        lint n;
        cin >>n; 
        map<lint,lint> mp;
        map<lint,lint> mp2;
        rep(i,n){
            lint a;
            cin>>a;
            if(i%2==0)mp[a]++;
            else mp2[a]++;
        }
        vector<P> p;
        vector<P> p2;
        for(auto x:mp){
            p.push_back(make_pair(x.second,x.first));
        }
        for(auto x:mp2){
            p2.push_back({x.second,x.first});
        }
         p.push_back({0,0});
          p2.push_back({0,0});
        sort(all(p),greater<P>());
        sort(all(p2),greater<P>());
        if(p[0].second!=p2[0].second){
            cout<<n-p[0].first-p2[0].first<<endl;
        }else{
            lint x=max(p[0].first+p2[1].first,p[1].first+p2[0].first);
            cout<<n-x<<endl;
        }
  } 
      
      
    

  
          
  