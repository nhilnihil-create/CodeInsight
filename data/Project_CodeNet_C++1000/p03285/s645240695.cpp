#include<iostream>
using namespace std;

int main() {
  int N;
  bool yorn = false;
  
  cin >> N;
  
  for(int i=0; i<=20; i++) {
    for(int j=0; j<=14; j++) {
      if(i*4+j*7 == N) {
        yorn = true;
        break;
      }
    }
  }
  
  if(yorn == true) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}