//g++ -std=gnu++14 a.cpp
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <iostream>
#include <istream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <tuple>
#include <iomanip>
#include <random>
#include <math.h>
#include <stdio.h>

using namespace std;

#define ll long long
#define rep(i, n) for(ll i = 0; i < (n); i++)
ll MOD = 1e9 + 7;
int INF = 1 << 30;
ll INFL = 1LL << 60;

//xより小さいうちの最小のインデックス
ll tansaku1(ll x,vector<ll> &v){
  ll ok = 0;
  ll ng = v.size();
  if(v[0]>=x)return -1;
  while(ng-ok>1){
    ll mid = (ok+ng)/2;
    if(v[mid]>=x)ng = mid;
    else ok = mid;
  }
  return ok;
}

//xより大きいうちの最小のインデックス
ll tansaku2(ll x, vector<ll> &v){
  ll ng = -1;
  ll ok = v.size()-1;
  if(v[ok]<=x)return ok+1;
  while(ok-ng>1){
    ll mid = (ok+ng)/2;
    if(v[mid] <= x)ng = mid;
    else ok = mid;
  }
  return ok;
}



int main(){
  ll N;
  cin >> N;
  vector<ll> A(N),B(N),C(N);
  rep(i,N)cin >> A[i];

  rep(i,N)cin >> B[i];
  rep(i,N)cin >> C[i];
  sort(A.begin(),A.end());
  sort(B.begin(),B.end());
  sort(C.begin(),C.end());

  ll ans = 0;
  rep(i,N){
    ans += (tansaku1(B[i],A)+1)*(N-tansaku2(B[i],C));
    //cout << ans << endl;
  }

  cout << ans << endl;

/*
  cout << tansaku1(M,A) << endl;
  cout << tansaku2(M,A) << endl;
*/
}
