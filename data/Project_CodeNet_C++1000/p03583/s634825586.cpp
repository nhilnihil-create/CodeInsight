#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 1; i < (int)(n); i++)
using ll = long long;

int main() {
  ll n;
  cin >> n;
  rep(i,3501)rep(j,3501){
      ll ng=0,ok=3501;
      while(ok-ng>=2){
        ll mid=(ng+ok)/2;
        ll x=4*i*j*mid,y=n*i*j+n*i*mid+n*j*mid;
        if(x==y){
          cout << i << " "  << j << " " << mid;
          return 0;
        }
        else if(x>y) ok=mid;
        else ng=mid;
      }
      
  }
}