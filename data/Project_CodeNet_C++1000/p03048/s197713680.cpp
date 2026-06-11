#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  int r,g,b,n;
  cin >> r >> g >> b >> n;
  int ans=0;
  
  rep(i,n+1){
    rep(j,n+1){
      int rest = n-r*i-g*j;
      if(rest%b==0&&rest>=0) ans++;
    }
  }

  cout << ans;
}