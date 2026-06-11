#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int r, D;
  cin >> r >> D;

  int x;
  cin >> x;

  
  int size = x;
  for (int i = 0; i < 10; i++)
  {
    size = r * size - D;
    cout << size << endl;
    
  }
}