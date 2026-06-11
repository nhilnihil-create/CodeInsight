#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repo(i,n) for(int i = 1; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define np next_permutation
#define umap unordered_map
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define mod 1000000007
#define pi acos(-1.0)
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }
ll jou(ll N, ll P){if(P==0) return 1;
    if(P%2==0){ll t = jou(N, P/2);return t*t % mod;
    }return (N * jou(N, P-1)) % mod;}  //jou(n,mod-2)で逆元
//intの最大値2147483647 ≒ 2×10^9
//long longの最大値9223372036854775807 ≒ 9×10^18
//'0'+=16;        で大文字に
//'大文字'+=32;    で小文字に
//  cout << fixed << setprecision (20);   小数点以下2０桁まで
//実行時間制約2秒では２×10^8回くらいまで計算できる


int main() {
  int n,a,b,c;
  cin>>n>>a>>b>>c;
  
  vector<int> p(n);
  rep(i,n){
  cin>>p[i];  
  }
  
  ll ans=9000000000000000000;
  
  rep(i,(1<<n)){
    rep(j,(1<<n)){
      int ay=0;
      int by=0;
      int cy=0;
      ll mp=-30;
      rep(k,n){
        if((i & (1<<k)) && (j & (1<<k))) {
          ay+=p[k];
          mp+=10;
        }
        if((i & (1<<k)) && !(j & (1<<k))) {
          by+=p[k];
          mp+=10;
        }
        if(!(i & (1<<k)) && (j & (1<<k))) {
          cy+=p[k];
          mp+=10;
        }
      }
      if(ay==0||by==0||cy==0) continue;
      mp+=abs(a-ay)+abs(b-by)+abs(c-cy);
      ans=min(ans,mp);
    }
  }
  
  cout << ans << endl;
  
}
