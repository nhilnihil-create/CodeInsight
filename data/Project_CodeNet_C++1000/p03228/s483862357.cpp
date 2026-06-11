#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int (i) = 0; i < (n); i++)

int main(){
  int a, b, k;
  cin >> a >> b >> k;
  rep(i, k){
    if(i % 2 == 0){
      if(a % 2) a--;
      a /= 2;
      b += a;
    }
    else {
      if(b % 2) b--;
      b /= 2;
      a += b;
    }
  }
  cout << a << " " << b << endl;
}	