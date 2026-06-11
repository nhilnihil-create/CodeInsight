#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll n,m;
  cin >> n >> m;
  priority_queue<ll, vector<ll>, greater<ll>> pq;
  rep(i,n){
    ll a;
    cin >> a;
    pq.push(a);
  }
  vector<pair<ll,ll>> b(m);
  rep(i,m){
    ll c,d;
    cin >> c >> d;
    b.at(i)=make_pair(d,c);
  }
  sort(b.begin(),b.end());
  reverse(b.begin(),b.end());
  ll i,j;
  for(i=0;i<m;i++){
    for(j=0;j<b.at(i).second;j++){
      ll q=pq.top();
      if(q<b.at(i).first){
        pq.pop();
        pq.push(b.at(i).first);
      }else{
        break;
      }
    }
  }
  ll sum=0;
  while(!pq.empty()){
    ll cp=pq.top();
    sum+=cp;
    pq.pop();
  }
  cout << sum;
}