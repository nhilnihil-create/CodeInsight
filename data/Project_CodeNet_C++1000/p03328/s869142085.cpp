#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int a, b;
  cin >> a >> b;

  int order = b - a;

  int east = 0;

  for (int i = 1; i < order + 1; i++)
  {
    east += i;
  }
  
  cout << east - b << endl;
}