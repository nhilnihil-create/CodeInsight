#include <bits/stdc++.h>
#pragma once
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
typedef long long ll;
typedef long double lb;
#define int long long
#define double long double
#define endn "\n"
typedef pair<int,int> P;
const int MOD = 1000000007;
const ll INF = 1e16;
const double EPS = 1e-10;
const double PI = 3.141592653589793;
template<class T> inline bool chmin(T& a, T b){if(a>b){a = b;return 1;}return 0;}
template<class T> inline bool chmax(T& a, T b){if(a<b){a = b;return 1;}return 0;}
const pair<int,int> fd[] = {make_pair(1,0),make_pair(-1,0),make_pair(0,1),make_pair(0,-1)}; 


////////////////////////////////////////////////////////////////////

int n,k;P p[110000];bool s[110000];
deque<int> deq;
signed main(){
  cin>>n>>k;
  rep(i,n){
    cin>>p[i].second>>p[i].first;
  }
  sort(p, p+n, greater<P>());
  int ans = 0, sum = 0, i = 0, v = 0;
  rep(j,k){
    sum += p[j].first;
    if(!s[p[j].second]){
      v++;
      s[p[j].second] = true;
    }else{
      deq.push_back(p[j].first);
    }
    i++;
  }
  ans = sum + v*v;
  while(i < n && !deq.empty()){
    if(!s[p[i].second]){
      sum -= deq.back();deq.pop_back();
      sum += p[i].first;
      s[p[i].second] = true;
      v++;
      chmax(ans, sum+v*v);
    }
    i++;
  }
  cout << ans << endl;
}

