#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main(){
  int cnt=0;
  int n,h;
  cin>>n>>h;
  vector<P> ab(n);
  rep(i,0,n){
    int a,b;
    cin>>a>>b;
    ab[i]=mp(a,b);
  }
  //////////////
  sort(all(ab));
  reverse(all(ab));
  ll amax=ab[0].first;
  ////////////////////////////
  rep(i,0,n){
    swap(ab[i].first,ab[i].second);
  } 
  P mx;
  mx=ab[0];
      int a=mx.second,b=mx.first;
  sort(all(ab));
  reverse(all(ab));
  /////////////////////////////
  int v=0;
  rep(i,0,n){
   if(ab[i]==mx&&v==0){
     
     v++;
     continue;
   }
    if(ab[i].first<amax) break;
    if(ab[i].first<b&&h-b<=0) break;
    cnt++;
    h-=ab[i].first;
    
    if(h<=0) break;
   
  }
 
    ////int a=mx.second,b=mx.first;
    while(h>b){
      cnt++;
      h-=a;
    }
  if(h>0) cnt++;
  
  
  
  cout<<cnt<<endl;
}
/*
a(n)の最大値　amax 以下のbを持つ剣は使わない
amax 以外の剣で使うものを投げる
amax の剣のb の値以下になるまでa減らす
b減らして倒す。
*/


