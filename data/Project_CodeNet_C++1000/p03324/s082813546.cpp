#include <bits/stdc++.h>
using namespace std;

int main() {
  long long D,N;
  cin >> D >> N;
  if(N == 100){
    N = 101;
  }
  if(D == 0){
    cout << N << endl;
  }
  else if(D == 1){
    cout << N*100 << endl;
  }
  else{
    cout << N*10000 << endl;
  }
}
