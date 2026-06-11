#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  int n,y;
  cin >> n >> y;

  rep(i,n+1){
    rep(j,n-i+1){
      int k = n-i-j;
      if(k<0)continue;
      if(10000*i+5000*j+1000*k==y) {
        cout << i << " " << j << " " << k;
        return 0;
      }
    }
  }

  cout << "-1 -1 -1";
}