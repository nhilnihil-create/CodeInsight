#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 10000000000000;
#define all(v) v.begin(), v.end()

int main(){
  ll N,K,m=0;
  
  cin >> N >> K;
  vector<ll> V(N);
  rep(i,N){
    cin >> V.at(i);
  }
  rep(i,N+1){
    for(ll j=N+1;j>i;j--){
      ll t=0;
      priority_queue<ll,vector<ll>,greater<ll>> Q;
      rep(k,i){
        t+=V.at(k);
        Q.push(V.at(k));
      }
      if(i+N+1-j>K) break;
      for(ll k=N-1;k>j-2;k--){
        t+=V.at(k);
        Q.push(V.at(k));
      }
      rep(k,K-(i+N+1-j)){
        if(!Q.empty()&&Q.top()<0){
          t-=Q.top();
          Q.pop();
        }
      }
      m=max(m,t);
    }
  }
  cout << m << endl;
      
      
}
      