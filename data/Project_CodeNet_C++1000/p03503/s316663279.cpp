#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <utility>
#include<vector>
#include<iomanip>
#include<map>
#include <queue>
#include<cmath>
#include<cstdio>
#include<iomanip>
#include<set>
#include <bits/stdc++.h>
 
using namespace std;
using ll = long long int;
 
#define REP(i,n) for(ll i=0;i<(ll)(n);i++) //REP(i, 5) cout<<i;
#define REPD(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define MOD 1000000007 //10^9+7
//#define MOD 1
 
ll gcd(ll a, ll b) {
  ll tmp;
  if ( b > a) {
    tmp = a;
    a = b;
    b = tmp;
  }
  while (a % b !=0) {
    tmp = b;
    b = a % b;
    a = tmp;
  }
  return b;
}
 
const int MAX = 1000;
 
ll table[MAX][MAX];
 
// テーブルを作る前処理
void COMinit() {
    table[0][0] = table[0][1] = 1;
    FOR(i, 1, MAX-1){
      FOR(j, 0, i+1){
        if(j==0) table[i][j] = 1;
        else if(j == i+1) table[i][j] = 1;
        else table[i][j] = table[i-1][j-1]+table[i-1][j];
      }
    }
}
 
// 二項係数計算
ll COM(ll n, ll k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return table[n-1][k];
}

void sosuu(ll n, vector<ll> &v){

  vector<ll> num(n, 0);

  FOR(i, 1, sqrt(n)){
    if(num[i]==0){
      FOR(j, 0, n/i){
        num[i+(j*i)] = 1;
      }
    }
  }
  REP(i, n){
    if(num[i]==0) v.push_back(i+1);
  }
}

ll SORT(int n, vector<pair<ll, ll>> &v, int start){
  sort(v.begin()+start, v.end());
  return v[n-1].first;
}


int main(void){
  ll n;
  cin>>n;
  ll ans = -1000000000;
  ll F[n][10];
  ll P[n][11];

  REP(i, n){
    REP(j, 10){
      ll x;
      cin>>x;
      F[i][j] = x;
    }
  }

  REP(i, n){
    REP(j, 11){
      ll x;
      cin>>x;
      P[i][j] = x;
    }
  }


  for(int bit=1;bit<(1<<10);++bit){

    vector<ll> v;
    for(int i=0;i<10;i++){
      if(bit & (1<<i)) v.push_back(i);
      //cout<<i<<" ";
    }
    //cout<<endl;

    ll sum = 0;
    REP(i, n){
      ll count = 0;
      REP(j, v.size()){
        count += F[i][v[j]];
      }
      sum += P[i][count];
    }
    ans = max(ans, sum);
  }

  cout<<ans<<endl;
  return 0;


}