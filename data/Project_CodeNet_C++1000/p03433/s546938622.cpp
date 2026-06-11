#include<bits/stdc++.h>
using namespace std;

int main() {
  int N, a;
  cin >> N >> a;
  
  int r = N % 500;
  
  if (r <= a) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
