#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;

int r=0, D=0, x=0;

int calc(int r, int D, int x){
  return r * x - D;
}

int main(){
  cin >> r >> D >> x;
  rep(i, 10){
    x = calc(r, D, x);
    cout << x << endl;
  }
}