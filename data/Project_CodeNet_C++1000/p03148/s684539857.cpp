#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,a,b) for(int i=(a);i<(b);++i)

template<class T> inline void chmin(T& a, T b) {if (a > b) a = b;}
template<class T> inline void chmax(T& a, T b) {if (a < b) a = b;}

//vector出力
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){
  o<<"{";
  for(int i=0;i<(int)v.size();i++) o << (i>0?", ":"") << v[i];
  o<<"}";
  return o;
}



ll const mod=1e9+7;
int main() {
  int N,K,tt; ll x=0,d,res=0,tmp=0;
  cin >> N >> K;
  vector<ll> val(N,-1);
  vector<vector<ll>> td(N);
  rep(i,N) {
    cin >> tt >> d;
    tt--;
    td[i] = {d,tt};
  }
  sort(td.rbegin(),td.rend());
  priority_queue<ll,vector<ll>,greater<>> pq;
  
  rep(i,N) {
    auto t = td[i];
    if (i<K){
      if (val[t[1]]==-1) {
        x++;val[t[1]]++;tmp+=t[0];
      }
      else {
        tmp+=t[0];
        pq.push({t[0]});
      }
    }
    else{
      if (val[t[1]]==-1) {
        if (pq.empty()) break;
        x++;val[t[1]]++;tmp+=t[0]-pq.top();
        pq.pop();
      }
      else continue;
    }
    chmax(res,tmp+x*x);
  }
  cout << res << endl;
}