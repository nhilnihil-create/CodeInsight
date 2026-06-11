#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); ++i)
using namespace std;

int main(){
  int n, x0, y0, x1, y1, t0, t1;
  int kyori, jikan;
  x1=0; y1=0; t1=0;
  cin >> n;
  int ans=0;
  rep(i,n){
    cin >> t0 >> x0 >> y0;
    kyori = abs(x0 - x1) + abs(y0 - y1);
    jikan = t0 - t1;
    x1=x0; y1=y0; t1=t0;
    if(kyori > jikan || kyori%2 != jikan%2){
      ans = 0;
    }else{
      ans = 1;
    }
  }
  cout << (ans?"Yes":"No") << endl;
  return 0;
}