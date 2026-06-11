#include<iostream>
using namespace std;

int main() {
  int N;
  cin>> N;
  string S;
  cin >> S;
  int Rcount = 0;
  int Bcount = 0;
  for(int i = 0;i < N;i++) {
    if(S.at(i) == 'R') {
      Rcount++;
    }
    else {
      Bcount++;
    }
  }
  if(Rcount > Bcount) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}