#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<typename T> bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<typename T> bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef tuple<ll,ll,ll> tlll;
typedef tuple<int,int,int> tiii;
const ll mod=1e9+7;
const int inf=1<<30;

const int MAX=2e6+1; //nCrのnのMAX+1
ll fac[MAX],finv[MAX],inv[MAX],sinv[MAX];

void cominit(){
  fac[0]=fac[1]=1;
  finv[0]=finv[1]=1;
  inv[1]=1;
  sinv[0]=0,sinv[1]=1;
  for (int i=2;i<MAX;i++){
    fac[i]=fac[i-1]*i%mod;
    inv[i]=mod-inv[mod%i]*(mod/i)%mod;
    finv[i]=finv[i-1]*inv[i]%mod;
    sinv[i]=sinv[i-1]+inv[i]%mod;
  }
}
ll com(int n,int k){ //1≦k≦n≦10^7
  if (n<k) return 0;
  if (n<0||k<0) return 0;
  return fac[n]*(finv[k]*finv[n-k]%mod)%mod;
}
//Add cominit(); in main function.

int main(){
  cominit();
  int n; cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  ll ans=0;
  rep(i,n){
    ll left=(sinv[i+1]-1+mod)%mod;
    ll right=(sinv[n-1-i+1]-1+mod)%mod;
    ans+=a[i]*fac[n]%mod*(left+right+1)%mod;
    ans%=mod;
  }
  cout << ans << endl;
}