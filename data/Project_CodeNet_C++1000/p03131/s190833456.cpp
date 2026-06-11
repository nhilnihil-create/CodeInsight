#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for( ll i = 0;i < (ll) n;++i)

int main(){
  ll k,a,b;
  cin >> k >> a >> b;
  ll bis = 1;
  ll m = 0;
  if( a+1 >= b ){
    cout << k+1 << endl;
    return 0;
  }else{
    rep(i,k){
      if( i == k-1 ){
        if( m != 0 ){
          m--;
          bis += b;
        }else{
          bis++;
        }
        break;
      }
      if( bis < a && m == 0 ){
        bis++;
      }else if( bis >= a && m == 0 ){
        m++;
        bis -= a;
      }else if( m != 0 ){
        m--;
        bis += b;
      }else{
        bis++;
      }
    }
  }
  cout << bis << endl;
  return 0;
}