#include <bits/stdc++.h>
using namespace std;

int main() {
  char N,S,t=3;
  int C[5] = {0};
  cin >> N;
  while(N--){
    cin >> S;
    if(S=='Y')
      t=4;
  }
  if(t==3)
    cout << "Three" << endl;
  else
    cout << "Four" << endl;
}
