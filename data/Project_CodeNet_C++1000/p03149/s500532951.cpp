#include <bits/stdc++.h>
using namespace std;

int main() {
  int ar[4];
  for(int i = 0; i < 4; i++){
    cin >> ar[i];
  }
  sort(ar, ar+4);
  if(ar[0] == 1 && ar[1] == 4 && ar[2] == 7 && ar[3] == 9){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
  return 0;
}
