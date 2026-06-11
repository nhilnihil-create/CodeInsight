#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int n,y;
  cin >> n >> y;

  rep(i,n+1){
    if(i>n) break;

    rep(j,n+1){
      if(i+j>n) break;

      int k = n - i - j;

      if(i*10000+j*5000+k*1000==y){
        printf("%d %d %d\n",i,j,k);
        return 0;
      }

    }

  }

  printf("-1 -1 -1\n");

  return 0;
}