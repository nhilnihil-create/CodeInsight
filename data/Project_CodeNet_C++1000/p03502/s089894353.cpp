#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  int fN;
  fN = N / 100000000
    + N / 10000000 - (N / 100000000) * 10
    + N / 1000000 - (N / 10000000) * 10
    + N / 100000 - (N / 1000000) * 10
    + N / 10000 - (N / 100000) * 10
    + N / 1000 - (N / 10000) * 10
    + N / 100 - (N / 1000) * 10
    + N / 10 - (N / 100) * 10
    + N % 10;
  
  if (N % fN == 0){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}
