#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int r, D, x;
  scanf("%d %d %d", &r, &D, &x);
  
  int S = x;
  for(int i = 0; i < 10; i++){
    S = r*S -D;
    cout << S << endl;
  }
}
    