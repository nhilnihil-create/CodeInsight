#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 10000000000000;
#define all(v) v.begin(), v.end()


int main(){
  ll A,B,Q;
  cin >> A >> B >> Q;
  vector<ll> s(A),t(B);
  rep(i,A) cin >> s.at(i);
  rep(i,B) cin >> t.at(i);
  rep(i,Q){
    ll x,m=INF;
    cin >> x;
    auto a=lower_bound(all(s),x);
    auto b=t.begin();
    if(a!=s.end()){
      auto b=lower_bound(all(t),*a);
      if(b!=t.end()){
        m=min(m,abs(x-*a)+abs(*b-*a));
      }
      if(b!=t.begin()){
        b--;
        m=min(m,abs(x-*a)+abs(*b-*a));
      }
    }
    if(a!=s.begin()){
      a--;
      b=lower_bound(all(t),*a);
      if(b!=t.end()){
        m=min(m,abs(x-*a)+abs(*b-*a));
      }
      if(b!=t.begin()){
        b--;
        m=min(m,abs(x-*a)+abs(*b-*a));
      }
    }
    a=lower_bound(all(t),x);
    if(a!=t.end()){
      auto b=lower_bound(all(s),*a);
      if(b!=s.end()){
        m=min(m,abs(x-*a)+abs(*b-*a));
      }
      if(b!=s.begin()){
        b--;
        m=min(m,abs(x-*a)+abs(*b-*a));
      }
    }
    if(a!=t.begin()){
      a--;
      b=lower_bound(all(s),*a);
      if(b!=s.end()){
        m=min(m,abs(x-*a)+abs(*b-*a));
      }
      if(b!=s.begin()){
        b--;
        m=min(m,abs(x-*a)+abs(*b-*a));
      }
    }
    cout << m << endl;
  }
    
}
