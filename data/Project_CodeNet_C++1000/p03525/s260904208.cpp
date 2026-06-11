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
      cin>>n;
      lint d[13];
      fill(d,d+13,0);
      lint ans=0;
      rep(i,n){
          lint x; 
          cin>>x;
        d[x]++;
        }
        if(d[0]>0)cout<<0<<endl;
        else{
        rep(i,13){
            if(d[i]>2){
                cout<<0<<endl;
                return 0;
            }
        }
            if(d[12]>1){
                cout<<0<<endl;
                return 0;
            }
            vector<lint> x;
            vector<lint>y;
            x.push_back(0);
            rep(i,13){
                if(d[i]==2){
                    x.push_back(i);
                    x.push_back(24-i);
                }
                if(d[i]==1)y.push_back(i);
            }
            lint t=y.size();
            rep(i,1<<t){
                vector<lint> z;
                z.resize(0);
                rep(j,t){
                    if(i&(1<<j))z.push_back(y[j]);
                    else z.push_back(24-y[j]);
                }
            rep(j,x.size())z.push_back(x[j]);
            lint mn=INF;
            rep(j,z.size()){
                repp(k,j+1,z.size()){
                mn=min({mn,abs(z[k]-z[j]),24-abs(z[k]-z[j])});
                }
            }
             ans=max(mn,ans);
        }
        cout<<ans<<endl;
        }

        }
      
    
  