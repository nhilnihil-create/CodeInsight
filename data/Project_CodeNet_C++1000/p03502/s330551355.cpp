#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  int fN = 0;
  cin >> N;
  
  for(int n = N; n > 0; n = n / 10){ 
    fN += n % 10;
  }
  if(N % fN == 0){
    cout << "Yes" << endl;
  }
  else cout << "No " << endl;
}