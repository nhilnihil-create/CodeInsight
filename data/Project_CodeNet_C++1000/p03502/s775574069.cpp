#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, fx=0, n;
  cin >> N;

  n=N;
  for (int i = 0; i < 8; i++){
    fx += n % 10;
    n /= 10;
  }
  
  if(N % fx == 0){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }

}