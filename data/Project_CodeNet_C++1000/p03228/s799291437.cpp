#include <bits/stdc++.h>
using namespace std;

int progressDif(long* n){
  int progress = 0;
  if(*n % 2 == 1)
    (*n)--;
  progress += (*n) / 2;
  return progress;
}

signed main() {
  long a,b;
  int k;
  cin >> a >> b >> k;
  for(int i = 0; i < k / 2; i++){
    int difA = progressDif(&a);
    a -= difA;
    b += difA;
    int difB = progressDif(&b);
    a += difB;
    b -= difB;
  }

  if(k % 2 == 1){
    int dif = progressDif(&a);
    a -= dif;
    b += dif;
  }


  cout << a << " " << b << endl;

}