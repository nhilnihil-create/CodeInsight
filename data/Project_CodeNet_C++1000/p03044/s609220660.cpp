#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 1000000000000000;
#define all(v) v.begin(), v.end()

//コストが正の場合
//vector<vector<P>> G(N,vector<P>(0));
void graphmake(ll E,vector<vector<P>> &G){
  rep(i,E){
    ll a,b,c;
    cin >> a >> b >> c;
    G.at(a-1).push_back(P(b-1,c));
    G.at(b-1).push_back(P(a-1,c));//有向なら消す
  }
}
//vector<ll> d(N);
void dijkstra(ll s,vector<ll> &d, vector<vector<P>> &G,ll V){
  priority_queue<P,vector<P>,greater<P>> que;
  rep(i,V) d.at(i)=INF;
  d.at(s)=0;
  que.push(P(0,s));
  while(!que.empty()){
    P p=que.top();
    que.pop();
    ll v=p.second;
    if(d.at(v)<p.first) continue;
    rep(i,G.at(v).size()){
      P e=G.at(v).at(i);
      if(d.at(e.first)>d.at(v)+e.second){
        d.at(e.first)=d.at(v)+e.second;
        que.push(P(d.at(e.first),e.first));
      }
    }
  }
}


int main(){
  ll N;
  cin >> N;
  vector<vector<P>> G(N,vector<P>(0));
  vector<ll> d(N);
  graphmake(N-1,G);
  dijkstra(0,d,G,N);
  rep(i,N){
    if(d.at(i)%2==0){
      cout << 0 << endl;
    }else{
      cout << 1 << endl;
    }
  }
}