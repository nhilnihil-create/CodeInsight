#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)

int main(){
  int n,m;
  cin >> n >> m;
  priority_queue<ll> pq;
  rep(i,n){
    ll x;
    cin >> x;
    pq.push(-x);
  }
  vector<pair<ll,ll>> qurey(m);
  rep(i,m){
    ll x,y;
    cin >> x >> y;
    qurey[i] ={-y,-x};
  }
  sort(qurey.begin(),qurey.end());
  //rep(i,m){
    //cout << "{" << qurey[i].first << qurey[i].second << "}" << endl;
  //}
  rep(i,m){
    rep(j,(-qurey[i].second)){
      ll tmp = -(pq.top());
      pq.pop();
      if (tmp < (-qurey[i].first)){
        pq.push(qurey[i].first);
      }else{
        pq.push(-tmp);
        break;
      }
    }
  }
  ll ans = 0;
  while(!pq.empty()){
    ll tmp = pq.top();
    pq.pop();
    //cout << -tmp << endl;
    ans += (-tmp);
  }
  cout << ans << endl;


    
  return 0;
}
