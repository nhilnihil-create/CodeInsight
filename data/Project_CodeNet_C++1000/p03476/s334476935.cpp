#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i) = 0; (i) <(n); (i)++) 
#define so(v) sort(v.begin(),v.end())
using ll = long long;
using vi=vector<int>;
using vvi=vector<vi>;
const int MAX = 510000;
const int MOD = 1000000007;
ll gcd(ll a, ll b)
{
   if (a%b == 0)
   {
       return(b);
   }
   else
   {
       return(gcd(b, a%b));
   }
}
ll lcm(ll a, ll b)
{
   return a * b / gcd(a, b);
}
long long fac[MAX], finv[MAX], inv[MAX];
// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
// 二項係数計算
long long com(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
int main() {
  ll MAX=111111;
  vector<int> s(MAX,1);
  s[0]=0;s[1]=0;
  for(int i=2;i<MAX;i++){
    if(s[i]!=1)continue;
    for(int j=i*2;j<MAX;j+=i)s[j]=0;
  }
  vector<ll> sum(MAX,0);
  sum[1]=0;
  for(int i=3;i<MAX;i+=2){
    if(s[i]==1&&s[(i+1)/2]==1)sum[i]=sum[i-2]+1;
    else sum[i]=sum[i-2];
  }
  int q;cin>>q;
  int a[q];
  rep(i,q){
    int l,r;
    cin>>l>>r;
    a[i]=sum[r]-sum[max(0,l-2)];
  }
  rep(i,q)cout<<a[i]<<endl;
}