#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >>N;
  if (N%1110<=9) {
    cout << "Yes" << endl;
  }
  else if (N%1000%111==0) {
    cout << "Yes" << endl;
  }
  else {
    cout <<"No"<< endl;
  }
}
