#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  ll n,y; cin >>n >>y;
  rep(i,n+1){
    rep(j,n-i+1){
      int k = n-i-j;
      if(10000*i+5000*j+1000*k==y){
        cout << i << " " << j << " " << k << endl;
        return 0;
      }
    }
  }
  cout << -1 << " " << -1 << " " << -1 << endl;
  return 0; 
}