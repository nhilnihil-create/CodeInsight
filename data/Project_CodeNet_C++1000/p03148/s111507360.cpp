#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<cstring>
#include<math.h>
#include<bitset>
#include<queue>
#include<set>
#include<iomanip>
#include<math.h>
#include<assert.h>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr long long INF = 1LL << 40;
const double INFD = 1e100;
const ll mod = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
// ----------------------------------------------------------------------------

int main(){
  ll N,K;
  cin >> N >> K;
  vector<vector<ll>> s(N);
  for(int i=0; i<N; i++){
    ll t,d;
    cin >> t >> d;
    t--;
    s[t].push_back(d);
  }
  for(auto &v: s){
    sort(v.begin(),v.end(),greater<ll>());
    if(v.empty()) v.push_back(-INF);
  }
  sort(s.begin(),s.end(),[&](vector<ll> a,vector<ll> b){
    return a[0] > b[0];
  });
  ll cur=0;
  priority_queue<ll> que;
  for(int i=0; i<K; i++){
    cur += s[i][0];
    for(int j=1; j<s[i].size(); j++){
      que.push(s[i][j]);
    }
  }
  for(int i=K; i<N; i++){
    for(int j=0; j<s[i].size(); j++){
      que.push(s[i][j]);
    }
  }
  ll res = cur + K*K;
  for(ll x=K-1; x>=1; x--){
    ll v = s[x][0];
    ll w = que.top();
    if(v < w){
      que.pop();
      cur += w;
      cur -= v;
    }else{
      break;
    }
    res = max(res, cur + x*x);
  }
  cout << res << endl;
  return 0;
}
