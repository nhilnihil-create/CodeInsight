#include<iostream>

using namespace std;

int main() {
  int N;
  cin >> N;
  
  bool OK =false;
  
  for(int c=0;c<=(N/4); c++) {
    for(int d=0; d<=(N/7); d++) {
      int total= 4*c + 7*d;
      if (total == N) OK = true;
    }
  }
  
  if(OK == false) cout << "No" << endl;
  else cout << "Yes" << endl;
}
 
