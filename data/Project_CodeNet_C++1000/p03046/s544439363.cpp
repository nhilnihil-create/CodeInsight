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


signed main(){
  int m,k;cin>>m>>k;
  if(powl(2,m) <= (double)k){
    cout << -1 << endl;return 0;
  }else if(m == 0){
    cout << "0 0" << endl;return 0;
  }else if(m == 1){
    if(k == 0)cout << "0 0 1 1" << endl;
    else cout << -1 << endl;
    return 0;
  }else{
    cout << k << " ";
    rep(i,pow(2,m)){
      if(i == k)continue;
      cout << i << " ";
    }
    cout << k << " ";
    for(int i = powl(2,m)-1;i >= 0;i--){
      if(i == k)continue;
      cout << i << (i == 0 ? "\n" : " ");
    }
  }
}

