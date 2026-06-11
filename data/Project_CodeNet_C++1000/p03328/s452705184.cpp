#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
using namespace std;

int main(){
  int a, b;
  cin >> a >> b;

  int TakasaNoSa = b - a;

  int HontoNoTakasa = 0;
  rep(i, 1, TakasaNoSa) {
    HontoNoTakasa += i;
  }

  cout << HontoNoTakasa - a << endl;
}
