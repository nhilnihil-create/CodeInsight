#include <bits/stdc++.h>
using namespace std;

int main() {
  int total, coin1;
  cin >> total >> coin1;
  
  if (total % 500 == 0){
    cout << "Yes" << endl;
  }else if (total % 500 < coin1) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}