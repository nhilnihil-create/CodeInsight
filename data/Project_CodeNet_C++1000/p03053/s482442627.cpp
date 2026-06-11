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
 
const int MAX = 2000;

long long fac[MAX], finv[MAX], inv[MAX];
 
// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
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

ll GetDigit(ll num){
    ll digit=0;
    while(num!=0){
        num /= 10;
        digit++;
    }
    return digit;
}


int main(void){

  ll h, w;
  cin>>h>>w;
  char M[h][w];
  queue<pair<ll, ll>> q;
  ll V[h][w];

  REP(i, h){
    REP(j, w){
      char x;
      cin>>x;
      M[i][j] = x;
      V[i][j] = -1;
      if(x=='#'){
        V[i][j]++;
        q.push(make_pair(i, j));
      }
    }
  }

  ll d[4][2] = {{1,0}, {-1,0}, {0, 1}, {0, -1}};

  while(q.size()!=0){
    pair<ll, ll> now = q.front();
    q.pop();
    ll sx = now.first;
    ll sy = now.second;
  //.cout<<sx<<","<<sy<<endl;

    REP(i, 4){
      ll nx = sx + d[i][0];
      ll ny = sy + d[i][1];
      if(nx>=0 && ny>=0 && nx<h && ny<w && M[nx][ny]=='.' && V[nx][ny]==-1){
        q.push(make_pair(nx, ny));
        V[nx][ny] = V[sx][sy]+1;
        M[nx][ny] = '#';
      }
    }
  }
  ll ans = 0;
  REP(i, h){
    REP(j, w){
      //cout<<V[i][j];
      ans = max(V[i][j], ans);
    }
   // cout<<endl;
  }
  cout<<ans<<endl;
  return 0;
  
}