#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

ll g(ll k,ll x){
  if(k==0LL){
    if(x%4LL==1LL||x%4LL==2LL) return 1LL;
    else return 0LL;
  }
  else {
    ll t = x%(1LL<<(k+1));
    if(t<(1LL<<k))return 0LL;
    if(t%2LL==0LL) return 1LL;
    else return 0LL;
  }
}

int main() {
  ll A,B;
  cin>>A>>B;
  bitset<60> bi;
  for(ll i = 0LL; i < 60LL; i++) {
    ll a = g(i,A-1LL);
    ll b = g(i,B);
    if((b-a)%2LL!=0LL)bi.set(i);
  }
  cout<<bi.to_ullong()<<endl;
}
  
