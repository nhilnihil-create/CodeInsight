#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll N;
  cin>>N;
  vector<vector<ll>> v(N,vector<ll>(3));
  for(ll i = 0LL; i < N; i++) {
    cin>>v[i][0]>>v[i][1]>>v[i][2];
  }
  pair<ll,ll> cen;
  ll H=0LL;
  for(ll i = 0LL; i <= 100LL; i++) {
    for(ll j = 0LL; j <= 100LL; j++) {
      bool ok = true;
      vector<ll> hi;
      for(auto x:v){
        hi.push_back(abs(x[0]-i)+abs(x[1]-j));
      }
      vector<ll> hiest;
      for(ll k = 0LL; k < N; k++) {
        if(v[k][2]==0LL)continue;
        hiest.push_back(hi[k]+v[k][2]);
      }
      ll t = hiest[0];
      for(ll x:hiest){
        if(t!=x) ok=false;
      }
      if(ok){
        bool ook=true;
        for(auto x:v){
          if(x[2]!=max(t-abs(x[0]-i)-abs(x[1]-j),0LL))ook=false;
        }
        if(ook){
          cen.first=i;
          cen.second=j;
          H=t;
        }
      }
    }
  }
  cout<<cen.first<<" "<<cen.second<<" "<<H<<endl;
}