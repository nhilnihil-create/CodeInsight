#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,K;
  cin >> N >> K;
  if(N>=13){
    cout << K << endl;
    return 0;
  }
  else if(N<=5){
    cout << 0 << endl;
    return 0;
  }
  else{
    cout << K/2 << endl;
  }
}
