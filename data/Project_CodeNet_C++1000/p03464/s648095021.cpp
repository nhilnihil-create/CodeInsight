#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll INF = 1LL<<60;

int main() {
  int K;
  cin>>K;
  vector<ll> v(K);
  for(int i = 0; i < K; i++) cin>>v[i];
  reverse(v.begin(),v.end());
  bool can = true;
  ll xM=2LL,xm=2LL;
  for(int i = 0; i < K; i++){
    if(xM/v[i]-(xm-1LL)/v[i]==0LL){
      can=false;
      break;
    }
    xM=(xM/v[i])*v[i]+v[i]-1;
    xm=((xm-1LL)/v[i]+1LL)*v[i];
  }
  if(can) cout<<xm<<" "<<xM<<endl;
  if(!can) cout<<-1<<endl;
}