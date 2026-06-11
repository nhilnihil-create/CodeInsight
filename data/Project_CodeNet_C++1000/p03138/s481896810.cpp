#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repo(i, n) for(int i=1; i<=n; i++)
#define ssort(a) sort(a.begin(), a.end())
#define INF 1001001001
#define INFll 100100100100100
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;

int main(){
  int n;
  ll k;
  cin >> n >>k;
  vector<ll> a(n);
  rep(i, n){
    cin >>a[i];
  }
  ll x=0;
  for(int i=41;i>=0; i--){
    ll tmp=1ll<<i;
    if(x+tmp>k)continue;
    int zero=0, one=0;
    rep(j, n){
      if((a[j]>>i)&1){
        one++;
      } else {
        zero++;
      }
    }
    if(zero>one){
      x+=tmp;
    }
  }
  ll ans=0;
  rep(i, n){
    ans+=a[i]^x;
  }
  cout << ans << endl;
  return 0;
}
