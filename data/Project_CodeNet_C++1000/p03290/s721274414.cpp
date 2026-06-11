#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll>
#define cvector vector<char>
#define svector vector<string>
#define lque queue<ll>
#define lpque priority_queue<ll>
#define dlpque priority_queue<ll,lvector,greater<ll>>
#define P pair<ll,ll>
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
#define rep(i,n) for(ll i=0; i<n; ++i)
#define print(a) cout << (a) << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll d,g,p,c,ans=1e9,ans_,tmp,lastdig;cin>>d>>g;
  vector<P> v(d);rep(i,d) {cin>>p>>c;v[i]=P(p,c);}
  ll l=1<<d;
  rep(bit,l) {
    tmp=0,ans_=0;
    rep(dig,d) {
      if((bit>>dig)&1) {
        tmp+=100*(dig+1)*v[dig].first+v[dig].second;
        ans_+=v[dig].first;
        if(tmp>=g) break;
      }
      else lastdig=dig;
    }
    if(g>tmp) {
      rep(i,v[lastdig].first) {
        tmp+=100*(lastdig+1);ans_++;
        if(tmp>=g) break;
      }
    }
    if(tmp>=g) ans=min(ans,ans_);
  }
  print(ans);
  return 0;
}