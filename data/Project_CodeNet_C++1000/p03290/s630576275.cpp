#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 1000000000000000000;
#define all(v) v.begin(), v.end()


int main(){
  ll D,G,ans=INF;
  cin >> D >> G;
  vector<ll> p(D),c(D);
  rep(i,D){
    cin >> p.at(i)>>c.at(i);
  }
  
  for (int tmp = 0; tmp < (1 <<(D)); tmp++) {
    bitset<10> s(tmp);
    ll t=0,x=0;
    rep(i,D){
      if(s.test(i)){
        x+=(100*(i+1)*p.at(i)) + c.at(i);
        t+=p.at(i);
      }
    }
    ll i=D-1;
    while(i>=0&&s.test(i)){
      i--;
    }
    if(x<G){
      rep(j,p.at(i)-1){
        x+=100*(i+1);
        t++;
        if(x>=G){
          break;
        }
      }
    }
    if(x<G){
      continue;
    }
    ans=min(t,ans);
  }
  cout << ans << endl;
}