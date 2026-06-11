#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int a,b;
  cin >> a >> b ;

  int total = 0;

  rep(i,2){
    if(a>b){
      total += a;
      a--;
    }
    else
    {
      total += b;
      b--;
    }
    
  }

  cout << total;


}
