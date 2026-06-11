#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

    //百の位
    //((N % 1000) - (N % 100)) / 100
    //十の位
    //((N % 100 ) - ( N % 10)) / 10

  if (((N % 1000) - (N % 100)) / 100 == ((N % 100 ) - ( N % 10)) / 10) {
      if ( ((N % 100 ) - ( N % 10)) / 10 == N / 1000) {
          cout << "Yes" << endl;
      }
      else if( ((N % 100 ) - ( N % 10)) / 10 == N % 10) {
          cout << "Yes" << endl;
      }
      else {
          cout << "No" << endl;
      }
    }

  else {
    cout << "No" << endl;
  }
}