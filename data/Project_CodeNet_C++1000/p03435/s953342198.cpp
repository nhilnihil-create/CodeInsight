#include <iostream>

using namespace std;
int main(){
  int c[3][3];
  int x[3] = {0}, y[3] = {0};
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      cin >> c[i][j];
      x[i] += c[i][j];
      y[j] += c[i][j];
    }
  }

  bool correct = true;
  for(int i = 0; i < 3; i++) {
    if((x[i]-x[(i+1)%3])%3 != 0) correct = false;
    if((y[i]-y[(i+1)%3])%3 != 0) correct = false;
  }

  if(correct) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}  
