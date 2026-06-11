#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N,keta=0;
  cin >> N;
  N++;
  long long n = N;
  for(int i=0; n>=1; i++){
    if(n/10 == 0){
      keta++;
      break;
    }
    n /= 10;
    keta++;
  }
  cout << (keta-1)*9+n-1 << endl;
}
