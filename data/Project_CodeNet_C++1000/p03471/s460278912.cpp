#include <bits/stdc++.h>
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
using namespace std;
using ll = long long;
using d = double;

int main(){
  int n,y;
  cin >> n >> y;
  rep(i,n+1){
    rep(j,n+1){
      if(10000*i+5000*j+1000*(n-i-j)==y && n-i-j>=0){
        printf("%d %d %d",i,j,n-i-j);
        return 0;
      }
    }
  }
  printf("%d %d %d",-1,-1,-1);
  return 0;
}