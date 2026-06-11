#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=1LL<<61;

int main() {
  ll n,a,b;
  cin >> n >> b >> a;
  if(a+b<=n+1&&a*b>=n) {
    for(ll i=a;i;i--) {
      if(i!=a) cout << " ";
      cout << i;
    }
    if(b!=1) {
      ll s=(n-a)/(b-1);
      ll m=(n-a)%(b-1);
      ll pre=a;
      while(--b) {
        ll cur=pre+s;
        if(m-->0) cur++;
        for(ll i=cur;i>pre;i--) {
          cout << " " << i;
        }
        pre=cur;
      }
    }
    cout << endl;
  }
  else cout << -1 << endl;
}