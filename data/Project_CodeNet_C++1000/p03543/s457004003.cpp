#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  if ((n - n % 10) % 111 == 0 || (n - (n / 1000) * 1000) % 111 == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}