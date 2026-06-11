#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
#include<bits/stdc++.h>
using namespace std;
int main(){
  ll a,b,k;
  cin >> a >> b >> k;
  int player = 1;
  rep(i,k){
    if(player == 1){
      if(a%2!=0){
        a--;
      }
      a /= 2;
      b += a;
      player = 2;
    }else{
      if(b%2!=0){
        b--;
      }
      b /= 2;
      a += b;
      player = 1;
    }
  }
  cout << a << " " << b << endl;
  return 0;
}